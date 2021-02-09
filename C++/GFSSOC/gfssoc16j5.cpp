#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100001, inf = 1 << 30;

int arr[MAXN][4], dp[MAXN][16], N;

void recurse(int c, int msk){
    if(msk == 0b1111) {
        dp[c][msk] = 0;
        return;
    }
    else if(c == 0) {
        dp[c][msk] = 0;
        return;
    }
    else if(dp[c][msk] == -inf){
        recurse(c - 1, msk);
        dp[c][msk] = dp[c - 1][msk];
        for (size_t i = 0; i < 4; i++)
        {
            int shi = 1 << i;
            if(!(msk & shi) && arr[c][i] > 0){
                recurse(c - 1, msk | shi);
                dp[c][msk] = max(dp[c][msk], dp[c - 1][msk | shi] + arr[c][i]);
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -inf);
    recurse(N, 0);
    cout << dp[N][0] << "\n";
}