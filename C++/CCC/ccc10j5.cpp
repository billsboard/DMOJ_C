#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

const int BOARD_SIZE = 9, inf = 1 << 30;
int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int dist[BOARD_SIZE][BOARD_SIZE], x, y, tx, ty;

void bfs(){
    queue<pii> q;
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(int), inf);
    q.push(make_pair(x, y));
    dist[x][y] = 0;
    while (!q.empty())
    {
        pii v = q.front();
        q.pop();

        if(v.first == tx && v.second == ty) return;

        for (size_t i = 0; i < 8; i++)
        {
            int nx = v.first + moves[i][0], ny = v.second + moves[i][1];
            if(nx > 0 && nx < 9 && ny > 0 && ny < 9 && dist[nx][ny] > dist[v.first][v.second] + 1){
                dist[nx][ny] = dist[v.first][v.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }   
    }   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> tx >> ty;
    bfs();
    cout << dist[tx][ty] << "\n";
}