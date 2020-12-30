#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct path
{
    int v, t, h;
    path(int v, int t, int h) : v(v), t(t), h(h) {}
};

struct compareTo {
    bool operator()(path const& p1, path const& p2){
        if(p1.t == p2.t) return p1.h > p2.h;
        return p1.t > p2.t;
    }
};
vector<path> adj[2001];
pair<int, int> dist[2001];
int N, M, K, A, B;
const int inf = 1 << 30;

int bfs(){
    priority_queue<path, vector<path>, compareTo> q;
    q.push(path(A, 0, 0));
    while (!q.empty())
    {
        path v = q.top();
        q.pop();
        if(v.v == B) return v.t;
        for(path p : adj[v.v]){
            if(p.h + v.h < K){
                path nxt = path(p.v, v.t + p.t, v.h + p.h);
                if(dist[p.v].first <= nxt.t && dist[p.v].second <= nxt.h) continue;

                dist[p.v].first = nxt.t; dist[p.v].second = nxt.h;
                q.push(nxt);
            }
        }
    }
    return -1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        adj[a].push_back(path(b, t, h));
        adj[b].push_back(path(a, t, h));
    }

    for (int i = 0; i <= N; i++)
    {
        dist[i] = make_pair(inf, inf);
    }
    cin >> A >> B;
    dist[A] = make_pair(0, 0);
    cout << bfs() << "\n";
}
