#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXN = 1001, inf = 1 << 30;

struct edge
{
    int v, d;
};

struct compare {
    bool operator() (const edge& a, const edge& b) {
        return a.d > b.d;
    }
};


int r[MAXN], g[MAXN], N, K, u, v, c, dist[MAXN];
vector<edge> adj[MAXN];

void bfs() {
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(dist[0]), inf);
    dist[1] = 0;
    priority_queue<edge, vector<edge>, compare> q;
    q.push(edge{1, 0});
    
    while (!q.empty())
    {
        edge v = q.top();
        q.pop();

        for(edge e : adj[v.v]) {
            int nd = dist[v.v] + e.d, t = g[e.v] + r[e.v];
            if(t != 0) {
                int cycle = nd % t;
                if(cycle >= g[e.v]) nd += t - cycle;
            }

            if(nd < dist[e.v]) {
                dist[e.v] = nd;
                q.push(edge{e.v, nd});
            }
        }
    }
    
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> u >> v >> c;
        adj[u].push_back(edge{v, c});
        adj[v].push_back(edge{u, c});
    }

    for (size_t i = 1; i <= K; i++)
    {
        cin >> g[i] >> r[i];
    }

    bfs();

    cout << dist[K] << "\n";
}
