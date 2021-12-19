#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 2001, inf = 1 << 30;

struct pt {
    int x, y;
};

char arr[MAXN][MAXN], c, mn = 'z';
int mx = -inf;
int M, N;
vector<pt> q, nxt;
bool visit[MAXN][MAXN];

void bfs() {
    q.push_back(pt{1, 1});

    while (!q.empty())
    {
        pt v = q[0];
        cout << arr[v.x][v.y];
        mn = 'z';
        mx = max((int) q.size(), mx);

        for(pt p : q){
            if(p.x + 1 <= N) mn = min(mn, arr[p.x + 1][p.y]);
            if(p.y + 1 <= M) mn = min(mn, arr[p.x][p.y + 1]);
        }

        for (pt p : q)
        {
            if(p.x + 1 <= N && arr[p.x + 1][p.y] == mn && !visit[p.x + 1][p.y]) {
                nxt.push_back(pt{p.x + 1, p.y});
                visit[p.x + 1][p.y] = true;
            }
            if(p.y + 1 <= M && arr[p.x][p.y + 1] == mn && !visit[p.x][p.y + 1]) {
                nxt.push_back(pt{p.x, p.y + 1}); 
                visit[p.x][p.y + 1] = true;
            }
        }
        
        q.clear();
        swap(q, nxt);
    }
     
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    q.reserve(6000);
    nxt.reserve(6000);

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    bfs();
    cout << "\n";
}