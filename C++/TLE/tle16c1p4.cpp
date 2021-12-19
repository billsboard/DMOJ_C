#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
const int MAXN = 101, inf = 1 << 30;

struct edge {
    int v, d;
};

struct compareTo {
    bool operator() (const edge& a, const edge& b) {
        return a.d > b.d;
    }
};

int dist[MAXN][MAXN], N, M, K, u, v, d, mx = -inf, arr[MAXN];
vector<edge> adj[MAXN];

void bfs(int st) {
    fill(&dist[st][0], &dist[st][0] + sizeof(dist[st]) / sizeof(dist[st][0]), inf);
    dist[st][st] = 0;
    priority_queue<edge, vector<edge>, compareTo> pq;
    pq.push(edge{st, 0});

    while (!pq.empty())
    {
        edge v = pq.top();
        pq.pop();

        for (edge e : adj[v.v])
        {
            if(dist[st][e.v] > dist[st][v.v] + e.d) {
                dist[st][e.v] = dist[st][v.v] + e.d;
                pq.push(edge{e.v, dist[st][v.v] + e.d});
            }
        }
    }
}

int getVal(int a, int b, int c) {
    unordered_set<int> tmp;
    int cnt = 0;

    for (size_t i = 1; i <= N; i++)
    {
        if(dist[a][i] <= K || dist[b][i] <= K || dist[c][i] <= K) tmp.insert(i);
    }

    for(int i : tmp) {
        cnt += arr[i];
    }

    return cnt;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v >> d;
        adj[u].push_back(edge{v, d});
        adj[v].push_back(edge{u, d});
    }

    for (size_t i = 1; i <= N; i++)
    {
        bfs(i);
    }
    
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = i + 1; j <= N; j++)
        {
            for (size_t k = j + 1; k <= N; k++)
            {
                mx = max(mx, getVal(i, j, k));
            }
        }
    }
    
    cout << mx << "\n";
}
