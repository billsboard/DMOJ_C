#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 10001, inf = 1 << 30;

int arr[MAXN], N;
double dp[MAXN];

void recurse(int p){
    if(p == 0) dp[p] = 0;
    else if(p == 1){
        dp[p] = arr[1];
    }
    else if(dp[p] == inf){
        recurse(p - 1);
        dp[p] = min(dp[p], dp[p - 1] + arr[p]);
        if(p >= 2){
            recurse(p - 2);
            dp[p] = min(dp[p], dp[p - 2] + max(arr[p], arr[p - 1]) + min(arr[p], arr[p - 1]) / 2.0);
        }
        if(p >= 3){
            recurse(p - 3);
            dp[p] = min(dp[p], dp[p - 3] + arr[p] + arr[p - 1] + arr[p - 2] - min(min(arr[p], arr[p - 1]), arr[p - 2]));
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.precision(1);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(dp[0]), inf);
    recurse(N);

    cout << fixed << dp[N] << "\n";
}