#include <iostream>
#include <algorithm>

using namespace std;
const int MAXM = 301, MAXR = 151, MAXU = 101, inf = 1 << 30;

int M, U, R, T[MAXR], F[MAXR], V[MAXR];
int dp[MAXR][MAXU][MAXM];

// First n, fill, time;

void recurse(int n, int f, int t) {
    if(n == 1) {
        if(f >= F[n] && t >= T[n]) dp[n][f][t] = V[n];
        else dp[n][f][t] = 0;
    }
    else if (dp[n][f][t] == -inf){
        if(f >= F[n] && t >= T[n]) {
            recurse(n - 1, f - F[n], t - T[n]);
            dp[n][f][t] = max(dp[n][f][t], dp[n - 1][f - F[n]][t - T[n]] + V[n]);
        }
        recurse(n - 1, f, t);
        dp[n][f][t] = max(dp[n][f][t], dp[n - 1][f][t]);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> U >> R;

    for (size_t i = 1; i <= R; i++)
    {
        cin >> V[i] >> T[i] >> F[i];
    }

    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), -inf);
    recurse(R, U, M);
    cout << dp[R][U][M] << "\n";
}