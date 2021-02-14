#include <iostream>

using namespace std;
const int MAXN = 501, inf = 1 << 30;

int arr[MAXN][MAXN], dp[MAXN][MAXN], N, M;

void recurse(int x, int y){
    if(x == 1 && y == 1){
        dp[x][y] = arr[1][1];
    }
    else if(dp[x][y] == inf){
        if(x - 1 > 0){
            recurse(x - 1, y);
            dp[x][y] = min(dp[x - 1][y] + arr[x][y], dp[x][y]);
        }
        if(y - 1 > 0){
            recurse(x, y - 1);
            dp[x][y] = min(dp[x][y - 1] + arr[x][y], dp[x][y]);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), inf);
    dp[1][1] = arr[1][1];
    recurse(N, M);
    cout << dp[N][M] << "\n";
}