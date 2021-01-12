#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

struct compareTo {
    bool operator()(pii a, pii b){
        return a.second > b.second;
    }
};

const int MAXN = 2001, inf = 1 << 30;
vector<pii> adj[MAXN];
int N, M, B, Q, dist[MAXN], x, y, t;
bool visit[MAXN];

void bfs(){
    priority_queue<pii, vector<pii>, compareTo> q;
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(int), inf);
    dist[B] = 0;
    q.push(make_pair(B, 0));
    while (!q.empty())
    {
        pii v = q.top();
        q.pop();
        if(visit[v.first]) continue;
        visit[v.first] = true;

        for(pii p : adj[v.first]){
            if(visit[p.first]) continue;
            if(dist[v.first] + p.second < dist[p.first]){
                dist[p.first] = dist[v.first] + p.second;
                q.push(make_pair(p.first, dist[v.first] + p.second));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> B >> Q;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y >> t;
        adj[x].push_back(make_pair(y, t));
        adj[y].push_back(make_pair(x, t));
    }

    bfs();
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x;
        cout << (dist[x] == inf ? -1 : dist[x]) << "\n";
    }   
}
