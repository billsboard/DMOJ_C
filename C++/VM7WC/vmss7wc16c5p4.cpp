#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 1, inf = 1 << 30;

int N, arr[3], dp[MAXN];

void recurse(int p){
    if(p == 0){
        dp[0] = 0;
        return;
    }
    else if(dp[p] == -inf){
        for(int i = 0; i < 3; i++){
            if(p - arr[i] < 0) continue;
            recurse(p - arr[i]);
            dp[p] = max(dp[p], dp[p - arr[i]] + 1);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(int), -inf);
    recurse(N);
    cout << dp[N] << "\n";
}
