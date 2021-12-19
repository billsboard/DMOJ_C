#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll inf = 1LL << 62;
const int MAXN = 131073 * 2;


struct edge {
    int v, d;
};

vector<edge> adj[MAXN];
int N, u, v, w, D, R;
ll dist[MAXN], mx = -inf;

void dfs(int p) {
    for(edge e : adj[p]) {
        dist[e.v] = dist[p] + e.d;
        dfs(e.v);
    }

    if(adj[p].size() == 0) {
        mx = max(mx, dist[p]);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R;
    for (size_t i = 0; i < ((1 << N) - 1); i++)
    {
        cin >> u >> v >> w >> D;
        adj[u].push_back(edge{v, D});
        adj[u].push_back(edge{w, 0});
    }

    dfs(1);

    cout << mx + R << "\n";
}
