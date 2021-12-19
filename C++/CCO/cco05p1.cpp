#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 101;

bool visit[MAXN][MAXN];
int mp[MAXN][MAXN], N, M, dirs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok(int x, int y, int z) {
    queue<pii> q;

    for (size_t i = 1; i <= N; i++)
    {
        if(mp[1][i] != x && mp[1][i] != y && mp[1][i] != z) continue;

        fill(&visit[0][0], &visit[0][0] + sizeof(visit) / sizeof(visit[0][0]), false);
        q.push(make_pair(1, i));
        while (!q.empty())
        {
            pii v = q.front();
            q.pop();

            if(visit[v.first][v.second]) continue;
            visit[v.first][v.second] = true;

            for (size_t j = 0; j < 4; j++)
            {
                int nx = v.first + dirs[j][0], ny = v.second + dirs[j][1];

                if(mp[nx][ny] != x && mp[nx][ny] != y && mp[nx][ny] != z) continue;
                if(nx < 1 || ny < 1 || nx > M || ny > N) continue; 

                q.push(make_pair(nx, ny));
            }
        }

        for (size_t j = 1; j <= N; j++)
        {
            if(visit[M][i]) return true;
        }
    }

    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 1; i <= M; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            cin >> mp[i][j];
        }
    }

    for (size_t i = 0; i <= 9; i++)
    {
        for (size_t j = i; j <= 9; j++)
        {
            for (size_t k = j; k <= 9; k++)
            {
                if(ok(i, j, k)) {
                    cout << i << " " << j << " " << k << "\n";
                    return 0; 
                }
            }
        }
    }
    
    cout << "-1 -1 -1\n";
}