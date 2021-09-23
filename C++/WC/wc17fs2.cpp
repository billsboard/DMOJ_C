#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 100000 + 1;
typedef long long ll;

struct edge {
    int a, b, d;
};

vector<edge> edges;
int djs[MAXN], sz[MAXN], N, M, x, y, z;
ll cnt;

int root(int p) {
    if(djs[p] == p) return p;
    return djs[p] = root(djs[p]);
}

bool conn(int a, int b) {
    return root(a) == root(b);
}

void uni(int a, int b) {
    int x = root(a), y = root(b);
    if(x == y) return;

    if(sz[x] > sz[y]) swap(x, y);
    djs[x] = y;
    sz[y] += sz[x];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for (size_t i = 0; i <= N; i++)
    {
        djs[i] = i;
        sz[i] = 1;
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        edges.push_back(edge{x, y, z}); 
    }

    sort(edges.begin(), edges.end(), [](const edge& u, const edge& v) -> bool {
        return u.d > v.d;
    });

    for(edge e : edges) {
        if(e.d > 0) {
            cnt += e.d;
            uni(e.a, e.b);
        }
        else {
            if(conn(e.a, e.b)) continue;
            cnt += e.d;
            uni(e.a, e.b);
        }
    }

    int r = root(1);
    for (size_t i = 2; i <= N; i++)
    {
        if(root(i) != r) {
            cout << "Impossible\n";
            return 0;
        }
    }
    

    cout << cnt << "\n";
}