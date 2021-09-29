#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAXN = 1001, inf = 1 << 30;

int N, M, dp[MAXN][MAXN];
string S, T;

void recurse(int x, int y) {
    if(dp[x][y] != inf) return;

    if(x == 0) dp[x][y] = (y + 2) / 3;
    else if (y == 0) dp[x][y] = (x + 2) / 3; 
    else {
        if(S[x - 1] == T[y - 1]) {
            recurse(x - 1, y - 1);
            dp[x][y] = min(dp[x][y], dp[x - 1][y - 1]);
        }
        else {
            for (int i = 1; i <= 3; i++)
            {
                if(x - i < 0) continue;
                recurse(x - i, y);
                dp[x][y] = min(dp[x][y], dp[x - i][y] + 1);
            }

            for (int i = 1; i <= 3; i++)
            {
                if(y - i < 0) continue;
                recurse(x, y - i);
                dp[x][y] = min(dp[x][y], dp[x][y - i] + 1);
            }

            recurse(x - 1, y - 1);
            dp[x][y] = min(dp[x][y], dp[x - 1][y - 1] + 1);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> S >> T;

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), inf);

    recurse(N, M);
    cout << dp[N][M] << "\n";
}