#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAXN = 1000, inf = 1 << 30;

char arr[MAXN];
int dp[MAXN][2], N, T, X, Y;
string s;

void recurse(int pos){
    if(pos == 1) {
        dp[pos][0] = 0;
        dp[pos][1] = 0;
        if(arr[pos] == 'C') dp[pos][1] = inf;
        else if(arr[pos] == 'J') dp[pos][0] = inf;
        return;
    }

    if(arr[pos] == 'C'){
        recurse(pos - 1);
        if(arr[pos - 1] == 'C') dp[pos][0] = dp[pos - 1][0];
        else if(arr[pos - 1] == 'J') dp[pos][0] = dp[pos - 1][1] + Y;
        else dp[pos][0] = min(dp[pos - 1][0], dp[pos - 1][1] + Y);
    }
    else if(arr[pos] == 'J'){
        recurse(pos - 1);
        if(arr[pos - 1] == 'J') dp[pos][1] = dp[pos - 1][1];
        else if(arr[pos - 1] == 'C') dp[pos][1] = dp[pos - 1][0] + X;
        else dp[pos][1] = min(dp[pos - 1][1], dp[pos - 1][0] + X);
    }
    else {
        recurse(pos - 1);
        if(arr[pos - 1] == 'J') {
            dp[pos][0] = dp[pos - 1][1] + Y;
            dp[pos][1] = dp[pos - 1][1];
        }
        else if(arr[pos - 1] == 'C'){
            dp[pos][0] = dp[pos - 1][0];
            dp[pos][1] = dp[pos - 1][0] + X;
        }
        else {
            dp[pos][0] = min(dp[pos - 1][0], dp[pos - 1][1] + Y);
            dp[pos][1] = min(dp[pos - 1][1], dp[pos - 1][0] + X);
        }
    }
}

// dp[][0] = C, dp[][1] = J

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        cout << "Case # " << t << ": ";
        cin >> X >> Y;
        cin >> s;
        N = s.size();
        for (size_t i = 0; i < N; i++)
        {
            arr[i + 1] = s[i];
        }
        fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), inf);
        recurse(N);
        
        if(arr[N] == 'J') cout << dp[N][1];
        else if(arr[N] == 'C') cout << dp[N][0];
        else cout << min(dp[N][1], dp[N][0]);
        cout << "\n";
        
    }
    
}