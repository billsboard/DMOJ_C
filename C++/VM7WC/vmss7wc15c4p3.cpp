#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 100001, inf = 1 << 30;

struct edge{
    int v, d;
    edge(int v, int d) : v(v), d(d) {};
};

struct compareTo{
    bool operator()(edge a, edge b){
        return a.d > b.d;
    }
};

vector<edge> adj[MAXN];
int distA[MAXN], distB[MAXN], N, M, W, x, y, d;

void bfs(){
    priority_queue<edge, vector<edge>, compareTo> q;
    fill(&distA[0], &distA[0] + sizeof(distA) / sizeof(int), inf);
    fill(&distB[0], &distB[0] + sizeof(distB) / sizeof(int), inf);
    distA[0] = 0; distB[W] = 0;
    q.push(edge(0, 0));
    while (!q.empty())
    {
        edge v = q.top();
        q.pop();
        for (edge e : adj[v.v])
        {
            if(distA[v.v] + e.d < distA[e.v]){
                distA[e.v] = distA[v.v] + e.d;
                q.push(edge(e.v, distA[e.v]));
            }
        }
    }

    q.push(edge(W, 0));
    while (!q.empty())
    {
        edge v = q.top();
        q.pop();
        for (edge e : adj[v.v])
        {
            if(distB[v.v] + e.d < distB[e.v]){
                distB[e.v] = distB[v.v] + e.d;
                q.push(edge(e.v, distB[e.v]));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    W = N - 1;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y >> d;
        adj[x].push_back(edge(y, d));
        adj[y].push_back(edge(x, d));
    }

    bfs();
    int mx = -inf;
    for (size_t i = 1; i < W; i++)
    {
        mx = max(mx, distA[i] + distB[i]); 
    }
    cout << mx << "\n";
}