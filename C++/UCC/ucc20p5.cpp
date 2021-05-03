#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXL = 1001, inf = 1 << 30;

int L, N, a, b, dist[MAXL], x, y;
vector<int> adj[MAXL];


void bfs(){
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(dist[0]), inf);
    queue<int> q;
    dist[a] = 0;
    q.push(a);
    
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int e : adj[v]){
            if(dist[e] > dist[v] + 1){
                dist[e] = dist[v] + 1;
                q.push(e);
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> a >> b >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    bfs();

    cout << dist[b] << "\n";
}