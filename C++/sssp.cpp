#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1001, inf = 9999999;

vector<pii> adj[MAXN];
int dist[MAXN], N, M;

void bfs(){
    fill(&dist[0], &dist[0] + sizeof(dist)/ sizeof(int), inf);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int v = q.front(); 
        q.pop();
        for (pii x : adj[v])
        {
            if(dist[x.first] > dist[v] + x.second){
                dist[x.first] = dist[v] + x.second;
                q.push(x.first);
            }            
        }
        
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].push_back(make_pair(y, d));
        adj[y].push_back(make_pair(x, d));
    }

    bfs();
    for (size_t i = 1; i <= N; i++)
    {
        if(dist[i] == inf) cout << "-1" << "\n";
        else cout << dist[i] << "\n";
    }
}