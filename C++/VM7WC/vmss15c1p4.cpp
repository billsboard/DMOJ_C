#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

struct edge{
    int v, d;
    edge(int v, int d) : v(v), d(d) {}
};

struct compareTo{
    bool operator() (const edge& a, const edge& b){
        return a.d > b.d;
    }
};

const int MAXN = 2001, inf = 1 << 30;

int N, M, T, G, x, y, d, cnt = 0;
vector<int> store;
vector<edge> adj[MAXN];
int dist[MAXN];

void bfs(){
    priority_queue<edge, vector<edge>, compareTo> q;
    q.push(edge(0, 0));
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), inf);
    dist[0] = 0;
    while (!q.empty())
    {
        edge v = q.top();
        q.pop();
        for (edge e : adj[v.v])
        {
            if(dist[e.v] > dist[v.v] + e.d){
                dist[e.v] = dist[v.v] + e.d;
                q.push(edge(e.v, dist[v.v] + e.d));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T >> N >> M >> G;
    for (size_t i = 0; i < G; i++)
    {
        cin >> x;
        store.push_back(x);
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y >> d;
        adj[x].push_back(edge(y, d));
    }

    bfs();
    for(int s : store){
        cnt += dist[s] <= T;
    }
    cout << cnt << "\n";
}
