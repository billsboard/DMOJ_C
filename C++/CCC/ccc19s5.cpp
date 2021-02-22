#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;
const int MAXN = 3001, inf = 1 << 30;

int N, arr[MAXN][MAXN], dp[MAXN][MAXN], K;
ll sum = 0;

void recurse(int k){
    if(k == 1) return;

    int ss = (2 * k + 3 - 1) / 3;
    if(k == 2) ss = 1;
    
    recurse(ss);
    for (int i = 1; i <= N - ss + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i][j], max(dp[i + k - ss][j], dp[i + k - ss][j + k - ss]));
        }
    }    
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }

    recurse(K);
    for (size_t i = 1; i <= N - K + 1; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            sum += dp[i][j];
        }   
    }
    
    cout << sum << "\n";
}