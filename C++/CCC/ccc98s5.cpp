#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 26, inf = 1 << 30;

int map[MAXN][MAXN], dist[MAXN][MAXN], T, N, h, oLevel;
const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs(){
    queue<pii> q;
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), inf);
    dist[1][1] = 0;
    q.push(make_pair(1, 1));
    while (!q.empty())
    {
        pii v = q.front();
        q.pop();
        for (size_t i = 0; i < 4; i++)
        {
            int x = v.first + dirs[i][0], y = v.second + dirs[i][1];
            if(x <= 0 || x > N || y <= 0 || y > N) continue;
            if(abs(map[v.first][v.second] - map[x][y]) > 2) continue;
            
            int oRequired = map[v.first][v.second] > oLevel || map[x][y] > oLevel;
            if(dist[v.first][v.second] + oRequired < dist[x][y]){
                dist[x][y] = dist[v.first][v.second] + oRequired;
                q.push(make_pair(x, y));
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (size_t i = 1; i <= N; i++)
        {
            for (size_t j = 1; j <= N; j++)
            {
                cin >> h;
                map[i][j] = h;
            }
        }

        oLevel = map[1][1];
        bfs();
        if(dist[N][N] == inf) cout << "CANNOT MAKE THE TRIP\n\n";
        else cout << dist[N][N] << "\n\n";
    }
}