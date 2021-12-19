#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 1e5 + 1;

struct edge {
    int u, v, d;
};

int N, K, cnt, djs[MAXN], sz[MAXN], c;
vector<edge> edj;

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

    cin >> N >> K;

    for (size_t i = 1; i <= N; i++)
    {
        djs[i] = i;
        sz[i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        cin >> c;
        edj.push_back(edge{i - 1, i, c});
        edj.push_back(edge{i, i - 1, c});
    }

    for (int i = 1; i <= N; i++)
    {
        if(i + K > N) break;
        edj.push_back(edge{i, i + K, 0});
        edj.push_back(edge{i + K, i, 0});
    }
    
    sort(edj.begin(), edj.end(), [] (edge& a, edge& b) ->  bool {
        return a.d < b.d;
    });


    for(edge e : edj) {
        if(conn(e.u, e.v)) continue;

        cnt += e.d;
        uni(e.u, e.v);
    }

    cout << cnt << "\n";
}