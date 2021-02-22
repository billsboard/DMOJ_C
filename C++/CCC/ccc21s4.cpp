#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXN = 200001, inf = 1 << 30;

vector<int> adj[MAXN];
int N, W, D, x, y, z, seg[4 * MAXN];
int dist[MAXN], train[MAXN], idx[MAXN];

void update(int i, int v, int rl, int rr, int p){
    if(rl == rr) seg[p] = v;
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid) update(i, v, rl, mid, p * 2);
        else update(i, v, mid + 1, rr, p * 2 + 1);
        seg[p] = min(seg[p << 1], seg[p * 2 + 1]);
    }
}

int query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return inf;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        return min(
            query(ql, qr, rl, mid, p << 1),
            query(ql, qr, mid + 1, rr, p * 2 + 1)
        );
    }
}

void bfs(){
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(dist[0]), inf);
    dist[N] = 0;
    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int e : adj[v])
        {
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

    cin >> N >> W >> D;
    for (size_t i = 0; i < W; i++)
    {
        cin >> x >> y;
        adj[y].push_back(x);
    }
    bfs();

    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        train[x] = i;
        idx[i] = x;
        update(x, i + dist[x], 1, N, 1);
    }

    for (size_t i = 0; i < D; i++)
    {
        cin >> x >> y;
        int cnvx = idx[x - 1], cnvy = idx[y - 1];
        int tx = train[cnvx], ty = train[cnvy];
        update(cnvx, ty + dist[cnvx], 1, N, 1);
        update(cnvy, tx + dist[cnvy], 1, N, 1);


        train[cnvx] = ty;
        train[cnvy] = tx;
        idx[x - 1] = cnvy;
        idx[y - 1] = cnvx;
        cout << min(query(1, N, 1, N, 1), min(train[N], dist[1])) << "\n";
    }
}

