#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 100001;

struct pt {
    int x, y, z, id;
};

struct edge {
    pt a, b;
};

int N, x, y, z, cst = 0;
pt arr[MAXN];
vector<edge> edges;
int djs[MAXN], sz[MAXN];

int root(int p) {
    if(djs[p] == p) return p;
    else return djs[p] = root(djs[p]);
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

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> z;
        arr[i] = {x, y, z, i};
    }


    sort(arr, arr + N, [](const pt& a, const pt& b) -> bool {return a.x < b.x;});
    for (size_t i = 1; i < N; i++)
    {
        edges.push_back(edge{arr[i - 1], arr[i]});
    }

    sort(arr, arr + N, [](const pt& a, const pt& b) -> bool {return a.y < b.y;});
    for (size_t i = 1; i < N; i++)
    {
        edges.push_back(edge{arr[i - 1], arr[i]});
    }

    sort(arr, arr + N, [](const pt& a, const pt& b) -> bool {return a.z < b.z;});
    for (size_t i = 1; i < N; i++)
    {
        edges.push_back(edge{arr[i - 1], arr[i]});
    }

    sort(edges.begin(), edges.end(), [](const edge& a, const edge&b) -> bool {
        return min(abs(a.a.x - a.b.x), min(abs(a.a.y - a.b.y), abs(a.a.z - a.b.z))) <
           min(abs(b.a.x - b.b.x), min(abs(b.a.y - b.b.y), abs(b.a.z - b.b.z)));
    });
    
    for (size_t i = 0; i <= N; i++)
    {
        djs[i] = i;
        sz[i] = 1;
    }

    for (edge e : edges)
    {
        if(conn(e.a.id, e.b.id)) continue;
        uni(e.a.id, e.b.id);
        cst += min(abs(e.a.x - e.b.x), min(abs(e.a.y - e.b.y), abs(e.a.z - e.b.z)));
    }

    cout << cst << "\n";
}