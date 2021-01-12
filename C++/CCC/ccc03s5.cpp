#include <iostream>
#include <queue> 
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 10001, inf = 1 << 30;
int C, R, D, W[MAXN], x, y, w;
vector<pii> adj[MAXN];
vector<int> dest;

void bfs(){
    queue<int> q;
    W[1] = inf;
    q.push(1);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(pii p: adj[v]){
            if(min(W[v], p.second) > W[p.first]){
                W[p.first] = min(W[v], p.second);
                q.push(p.first);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> R >> D;
    for (size_t i = 0; i < R; i++)
    {
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }
    for (size_t i = 0; i < D; i++)
    {
        cin >> x;
        dest.push_back(x);
    }
    
    bfs();
    int mv = inf;
    for (int i : dest)
    {
        mv = min(mv, W[i]);
    }

    cout << mv << "\n";
}