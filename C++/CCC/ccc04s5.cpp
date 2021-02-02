#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;
const int MAXN = 101;

int map[MAXN][MAXN], dp[MAXN][MAXN], M, N;
bool visit[MAXN][MAXN];
string s;

void calc(){
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    fill(&visit[0][0], &visit[0][0] + sizeof(visit) / sizeof(bool), 0);
    visit[N][0] = true;
    for (size_t i = 1; i <= M; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            if(!visit[j][i - 1]) continue;
            if(map[j][i] == -1){
                dp[j][i] = 0;
                visit[j][i] = false;
                continue;
            }
            else if(map[j][i - 1] == -1) continue;
            else if(j == N && i == M) {
                dp[j][i] = max(dp[j][i], dp[j][i - 1] + map[j][i]);
                continue;
            }

            visit[j][i] = true;
            int val;
            val = dp[j][i - 1] + map[j][i];
            int idx = j - 1;
            while (idx > 0 && map[idx][i] != -1)
            {
                val += map[idx][i];
                visit[idx][i] = true;
                dp[idx][i] = max(dp[idx][i], val);
                idx--;
            }

            idx = j + 1;
            int val2 = dp[j][i - 1] + map[j][i];
            while (idx <= N && map[idx][i] != -1)
            {
                val2 += map[idx][i];
                visit[idx][i] = true;
                dp[idx][i] = max(dp[idx][i], val2);
                idx++;
            }
            dp[j][i] = max(dp[j][i], dp[j][i - 1] + map[j][i]);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> N >> M;
        if(N == 0) break;

        for (size_t i = 0; i < MAXN; i++)
        {
            map[i][0] = -1;
        }
        for (size_t i = 1; i <= N; i++)
        {
            cin >> s;
            for (size_t j = 0; j < M; j++)
            {
                if(s[j] == '.') map[i][j + 1] = 0;
                else if(s[j] == '*') map[i][j + 1] = -1;
                else map[i][j + 1] = s[j] - '0';
            }
        }
        map[N][0] = 0;
        calc();
        cout << dp[N][M] << "\n";   
    }
}