#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int H, T, dp[1001][1001], h, t;
pair<int, int> arr[1001]; 

void recurse(int p, int t){
    if(t == 0) dp[p][0] = 0;
    else if(p == 1 && t >= arr[1].second) dp[1][t] = arr[1].first;
    else if(p == 1) dp[1][t] = 0;
    else if(dp[p][t] == -1){
        recurse(p - 1, t);
        dp[p][t] = dp[p - 1][t];
        if(t >= arr[p].second){
            recurse(p - 1, t - arr[p].second);
            dp[p][t] = max(dp[p][t], dp[p - 1][t - arr[p].second] + arr[p].first);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> T;
    for (size_t i = 1; i <= H; i++)
    {
        cin >> h >> t;
        arr[i] = make_pair(h, t);
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);
    
    recurse(H, T);
    cout << dp[H][T] << "\n";
}