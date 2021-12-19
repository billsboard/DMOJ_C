#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 501, MAXM = 501, inf = 1 << 30;

int N, M, K, pts[MAXN], arr[MAXN], dp[MAXN][MAXM];

void recurse(int n, int k) {
    if(dp[n][k] != -inf) return; 
    
    if(n == 1) {
        int pos = min(M, arr[n] + k);
        dp[n][k] = pts[pos];
    }
    else {
        for (int i = 0; i <= k; i++)
        {
            if(arr[n] + i > M) break;
            recurse(n - 1, k - i);
            dp[n][k] = max(dp[n][k], dp[n - 1][k - i] + pts[arr[n] + i]);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (size_t i = 0; i <= M; i++)
    {
        cin >> pts[i];
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), -inf);
    recurse(N, K);

    cout << dp[N][K] << "\n";
}