#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

struct compareTo{
    bool operator()(pair<int, int> const& a, pair<int, int> const& b){
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compareTo> q;
vector<pair<int, int>> adj[5001], shop;
const int inf = 1 << 30;
int dist[5001], N, K, T, D, a, b, c;
bool visit[5001];

void bfs(){
    fill(dist, dist + 5001, inf);
    q.push(make_pair(D, 0));
    dist[D] = 0;
    while (!q.empty())
    {
        pair<int, int> v = q.top();
        q.pop();
        if(visit[v.first]) continue;

        visit[v.first] = true;
        for(pair<int, int> p : adj[v.first]){
            if(dist[p.first] > dist[v.first] + p.second){
                dist[p.first] = dist[v.first] + p.second;
                q.push(make_pair(p.first, dist[v.first] + p.second));
            }
        }
    }
    
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    cin >> K;
    for (size_t i = 0; i < K; i++)
    {
        cin >> a >> c;
        shop.push_back(make_pair(a, c));
    }
    
    cin >> D;
    bfs();

    int m = inf;
    for(pair<int, int> p : shop){
        m = min(m, p.second + dist[p.first]);
    }
    cout << m << "\n";
}