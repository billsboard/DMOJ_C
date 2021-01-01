#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;
int arr[MAXN][MAXN], dp[MAXN][MAXN], N;

void recurse(int r, int c){
    if(r == N - 1) dp[r][c] = arr[r][c];
    else if(dp[r][c] == -1){
        recurse(r + 1, c);
        recurse(r + 1, c + 1);
        dp[r][c] = max(dp[r + 1][c], dp[r + 1][c + 1]) + arr[r][c];
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);
    recurse(0, 0);
    cout << dp[0][0] << "\n";
}