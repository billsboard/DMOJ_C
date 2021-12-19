#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXN = 201, inf = 1 << 29;

struct pt {
    int x, y;
};

pt P[27], s, a, b, c, d;
int dirs[][2] = {{0, 1},  {0, -1}, {1, 0}, {-1, 0}}, R, C, dist[MAXN][MAXN], cnt;
char mp[MAXN][MAXN], x;

void bfs(pt s, pt e, char target) {
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(dist[0][0]), inf);
    dist[s.x][s.y] = 0;
    queue<pt> q;
    q.push(s);

    while (!q.empty())
    {
        pt v = q.front();
        char y = mp[v.x][v.y];
        q.pop();

        if('A' <= y && y <= 'Z') {
            pt tp = P[y - 'A'];
            if(dist[tp.x][tp.y] > dist[v.x][v.y]) {
               dist[tp.x][tp.y] = dist[v.x][v.y];
               q.push(tp);
            }
        }
        else {
            for (size_t i = 0; i < 4; i++)
            {
                pt mv = {v.x + dirs[i][0], v.y + dirs[i][1]};
                if(mv.x < 1 || mv.y < 1 || mv.x > R || mv.y > C) continue;
                else if('a' <= mp[mv.x][mv.y] && mp[mv.x][mv.y] <= 'z') continue;
                else if(mp[mv.x][mv.y] == '#') continue;

                if(dist[mv.x][mv.y] > dist[v.x][v.y] + 1) {
                    dist[mv.x][mv.y] = dist[v.x][v.y] + 1;
                    q.push(mv);
                }    
            }
            
        }
    }
    
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> x;
            mp[i][j] = x;
            if(x == '0') s = {i, j};
            else if(x == '1') a = {i, j};
            else if(x == '2') b = {i, j};
            else if(x == '3') c = {i, j};
            else if(x == '4') d = {i, j};
            else if('a' <= x && x <= 'z') P[x - 'a'] = {i, j};
        }
    }
    
    bfs(s, a, '1');
    cnt += dist[a.x][a.y];

    bfs(a, b, '2');
    cnt += dist[b.x][b.y];

    bfs(b, c, '3');
    cnt += dist[c.x][c.y];

    bfs(c, d, '4');
    cnt += dist[d.x][d.y];

    if(cnt > inf) cout << -1 << "\n";
    else cout << cnt << "\n";
}