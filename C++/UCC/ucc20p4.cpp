#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1e6 + 1, inf = 1 << 30;

int arr[MAXN], dp[MAXN], N;

void recurse(int p){
    if(p == 0){
        dp[0] = 0;
    }
    else if(p == 1) {
        dp[p] = arr[p];
    }
    else if(dp[p] == inf){
        recurse(p - 1);
        dp[p] = dp[p - 1] + arr[p];
        if(p - 2 >= 0){
            recurse(p - 2);
            dp[p] = min(dp[p], dp[p - 2] + arr[p - 1] + arr[p] - min(arr[p], arr[p - 1]) / 4);
        }
        if(p - 3 >= 0){
            recurse(p - 3);
            dp[p] = min(dp[p],
                dp[p - 3] + arr[p - 2] + arr[p - 1] + arr[p] - min(min(arr[p], arr[p - 1]), arr[p - 2]) / 2
            );
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(dp[0]), inf);
    recurse(N);
    cout << dp[N] << "\n";
}