#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 101, inf = 1 << 30;
int dist[MAXN][MAXN], N, M, x, y;
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char t, arr[MAXN][MAXN], map[MAXN][MAXN];
vector<pii> cams;

void bfs(){
    queue<pii> q;
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), inf);
    dist[x][y] = 0;
    q.push(make_pair(x, y));
    while (!q.empty())
    {
        pii v = q.front();
        q.pop();

        if(map[v.first][v.second] == 'U'){
            if(map[v.first - 1][v.second] != 'W' && dist[v.first - 1][v.second] > dist[v.first][v.second]){
                dist[v.first - 1][v.second] = dist[v.first][v.second];
                q.push(make_pair(v.first - 1, v.second));
            }
            continue;
        }
        if(map[v.first][v.second] == 'D'){
            if(map[v.first + 1][v.second] != 'W' && dist[v.first + 1][v.second] > dist[v.first][v.second]){
                dist[v.first + 1][v.second] = dist[v.first][v.second];
                q.push(make_pair(v.first + 1, v.second));
            }
            continue;
        }
        if(map[v.first][v.second] == 'L'){
            if(map[v.first][v.second - 1] != 'W' && dist[v.first][v.second - 1] > dist[v.first][v.second]){
                dist[v.first][v.second - 1] = dist[v.first][v.second];
                q.push(make_pair(v.first, v.second - 1));
            }
            continue;
        }
        if(map[v.first][v.second] == 'R'){
            if(map[v.first][v.second + 1] != 'W' && dist[v.first][v.second + 1] > dist[v.first][v.second]){
                dist[v.first][v.second + 1] = dist[v.first][v.second];
                q.push(make_pair(v.first, v.second + 1));
            }
            continue;
        }
        
        for (size_t i = 0; i < 4; i++)
        {
            int nx = v.first + dirs[i][0], ny = v.second + dirs[i][1];
            if(map[nx][ny] != 'W' && dist[nx][ny] > dist[v.first][v.second] + 1){
                dist[nx][ny] = dist[v.first][v.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> t;
            if(t == 'C') cams.push_back(make_pair(i, j));
            else if(t == 'S'){
                x = i;
                y = j;
            }
            arr[i][j] = t;
            map[i][j] = t;
        }
    }

    for(pii p : cams){
        int px = p.first, py = p.second;
        map[px][py] = 'W';
        for (int i = px - 1; i >= 0; i--)
        {
            if(arr[i][py] == 'W') break;
            else if(arr[i][py] == '.' || arr[i][py] == 'S') map[i][py] = 'W';
        }

        for (int i = px + 1; i < N; i++)
        {
            if(arr[i][py] == 'W') break;
            else if(arr[i][py] == '.' || arr[i][py] == 'S') map[i][py] = 'W';
        }

        for (int i = py - 1; i >= 0; i--)
        {
            if(arr[px][i] == 'W') break;
            else if(arr[px][i] == '.' || arr[px][i] == 'S') map[px][i] = 'W';
        }

        for (int i = py + 1; i < M; i++)
        {
            if(arr[px][i] == 'W') break;
            else if(arr[px][i] == '.' || arr[px][i] == 'S') map[px][i] = 'W';
        }
    }

    if(map[x][y] == 'W'){
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                if(arr[i][j] == '.'){
                    cout << -1 << "\n";
                }
            }
        }
        return 0;
    }
    bfs();

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if(arr[i][j] == '.'){
                cout << (dist[i][j] == inf ? -1 : dist[i][j]) << "\n";
            }
        }
    }
}