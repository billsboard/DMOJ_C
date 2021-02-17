#include <iostream>

using namespace std;
const int MAXN = 100001, HIGH = 30, inf = 1 << 30;

int arr[MAXN], dp[MAXN], lB[HIGH], N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        int ans = 1;
        for (size_t j = 0; j < HIGH; j++)
        {
            int x = 1 << j;
            if(arr[i] & x){
                ans = max(ans, lB[j] + 1);
            }
        }
        dp[i] = ans;
        for (size_t j = 0; j < HIGH; j++)
        {
            int x = 1 << j;
            if(arr[i] & x){
                lB[j] = max(lB[j], dp[i]);
            }
        }
    }

    int mx = -inf;
    for (size_t i = 1; i <= N; i++)
    {
        mx = max(dp[i], mx);
    }

    cout << mx << "\n";
}