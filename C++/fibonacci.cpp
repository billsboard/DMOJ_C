#include <iostream>
#include <unordered_map>

using namespace std;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
ull N;
unordered_map<ull, ull> dp;

ull mod (ull a)
{
   ull b = MOD;
   ull ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

ull recurse(ull k){
    if(k <= 1) return 1;
    if(dp.find(k) == dp.end()){
        if(k & 1){
            ull a = recurse((k + 1) / 2) % MOD, b = recurse((k + 1) / 2 - 1) % MOD;
            dp[k] = ((b % MOD) * ((2 * a - b + MOD) % MOD)) % MOD;
        }
        else {
            ull a = recurse((k) / 2) % MOD, b = recurse((k) / 2 - 1) % MOD;
            dp[k] = ((a * a) % MOD + (b * b) % MOD) % MOD;
        }
        dp[k] = dp[k] % MOD;    
    }
    return dp[k] % MOD;
}

int main(){
    cin >> N;

    dp[0] = 1;
    dp[1] = 1;

    cout << recurse(N - 1) << "\n";
}