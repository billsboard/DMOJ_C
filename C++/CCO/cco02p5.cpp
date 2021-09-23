#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>  

using namespace std;
const int MAXN = 750 + 1;

struct pt {
    int x, y;
};

struct edge {
    int a, b;
    double d;
};

double dist(pt a, pt b) {
    return sqrt((double) (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

pt arr[MAXN];
vector<edge> edges, stk;
int djs[MAXN], sz[MAXN], N, M, a, b;
double cnt;

int root(int p) {
    if(djs[p] == p) return p;
    return djs[p] = root(djs[p]);
}

bool conn(int a, int b) {
    return root(a) == root(b);
}

void uni(int a, int b){ 
    int x = root(a), y = root(b);
    if(x == y) return;

    if(sz[x] > sz[y]) swap(x, y);
    djs[x] = y;
    sz[y] += sz[x];
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a >> b;
        arr[i] = {a, b};
    }
    
    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> a >> b;
        edges.push_back(edge{a, b, 0});
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            edges.push_back(edge{i, j, dist(arr[i], arr[j])});
        }
    }

    sort(edges.begin(), edges.end(), [](const edge& x, const edge& y) -> bool{
        return x.d < y.d;
    });

    for (size_t i = 0; i <= N; i++)
    {
        djs[i] = i;
        sz[i] = 1;
    }
    

    for(edge e : edges) {
        if(conn(e.a, e.b)) continue;

        uni(e.a, e.b);
        cnt += e.d;

        if(e.d > 0) {
            stk.push_back(e);
        }
    }
    
    
    cout << fixed << setprecision(2) << cnt << "\n";

    for(edge e : stk) {
        cout << e.a << " " << e.b << "\n";
    }
}