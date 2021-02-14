#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXN = 1001, inf = 1 << 30;

struct pt{
    int x, y;
};

char map[MAXN][MAXN];
int N, R, C, x, y, dist[MAXN][MAXN], dirs[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
pt S, O, tp[MAXN * MAXN];

bool inBound(pt p){
    return 0 <= p.x && p.x < R && 0 <= p.y && p.y < C;
}

void bfs(){
    queue<pt> q;
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), inf);
    dist[S.x][S.y] = 0;
    q.push(S);
    while (!q.empty())
    {
        pt p = q.front();
        q.pop();
        for (size_t i = 0; i < 4; i++)
        {
            pt x = {p.x + dirs[i][0], p.y + dirs[i][1]};
            if(!inBound(x) || map[x.x][x.y] == 'X') continue;
            if(dist[p.x][p.y] + 1 < dist[x.x][x.y]){
                dist[x.x][x.y] = dist[p.x][p.y] + 1;
                q.push(x);
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> x >> y;
    S = {x, y};
    cin >> x >> y;
    O = {x, y};
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        tp[i] = {x, y};
    }

    bfs();
    int reg = dist[O.x][O.y];
    int mx = -1;
    for (size_t i = 0; i < N; i++)
    {
        pt p = tp[i];
        if(dist[p.x][p.y] < reg){
            mx = max(mx, reg - dist[p.x][p.y]);
        }
    }

    cout << (mx == -1 ? 0 : mx) << "\n";
}