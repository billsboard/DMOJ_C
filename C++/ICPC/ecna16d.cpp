#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
const int MAXN = 101, MAXM = 2 * 4501, inf = 1 << 30;
typedef pair<int, int> pii;

struct edge {
    int v, d, moves;
};

struct compare {
    bool operator() (const edge& a, const edge& b) {
        if (a.moves == b.moves) return a.d > b.d;
        return a.moves > b.moves;
    }
};


unordered_map<string, int> mp;
vector<edge> adj[MAXM];
string langs[MAXN], u, v;
int N, M, idx = 1, dist[MAXM], mv[MAXM], c, cst = 0;



void bfs() {
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(dist[0]), inf);
    fill(&mv[0], &mv[0] + sizeof(mv) / sizeof(mv[0]), inf);
    dist[0] = 0; mv[0] = 0;
    queue<edge> pq;
    pq.push(edge{0, 0, 0});
    
    while (!pq.empty())
    {
        edge v = pq.front();
        pq.pop();

        for (edge p : adj[v.v])
        {
            if(mv[p.v] > mv[v.v] + 1 || (mv[p.v] == mv[v.v] + 1 && dist[p.v] > p.d)) {
                dist[p.v] = p.d;
                mv[p.v] = mv[v.v] + 1;
                pq.push(edge{p.v, dist[p.v], mv[p.v]});
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> langs[i];
        if(mp.find(langs[i]) == mp.end()) {
            mp[langs[i]] = idx;
            idx++;
        }
    }

    mp["English"] = 0;

    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v >> c;
        if(mp.find(u) == mp.end()) {
            mp[u] = idx;
            idx++;
        }
        if(mp.find(v) == mp.end()) {
            mp[v] = idx;
            idx++;
        }

        adj[mp[v]].push_back(edge{mp[u], c, 0});
        adj[mp[u]].push_back(edge{mp[v], c, 0});
    }

    bfs();

    for (size_t i = 0; i < N; i++)
    {
        if(dist[mp[langs[i]]] == inf) {
            cout << "Impossible\n";
            return 0;
        }
        cst += dist[mp[langs[i]]];
    }

    cout << cst << "\n";
}