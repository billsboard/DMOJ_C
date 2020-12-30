#pragma GCC optimize("Ofast") 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
bool shop[100001];
int aDist[100001], bDist[100001], N, M, K, A, B;
const int INF = 1 << 30;

void bfs(){
    queue<int> q;
    q.push(A);
    fill(aDist, aDist + 100001, INF);
    fill(bDist, bDist + 100001, INF);
    aDist[A] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int x : adj[v]){
            if(aDist[x] > aDist[v] + 1){
                aDist[x] = aDist[v] + 1;
                q.push(x); 
            }
        }
    }

    q = queue<int>();
    q.push(B);
    bDist[B] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int x : adj[v]){
            if(bDist[x] > bDist[v] + 1){
                bDist[x] = bDist[v] + 1;
                q.push(x); 
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> A >> B;
    for (int i = 0; i < K; i++)
    {
        int p;
        cin >> p;
        shop[p] = true;
    }

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();

    int d = INF;
    for (int i = 1; i <= N; i++)
    {
        if(shop[i]){
            d = min(d, aDist[i] + bDist[i]);
        }
    }
    cout << d << "\n";
}
