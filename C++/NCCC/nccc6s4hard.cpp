#include <iostream>

using namespace std;
const int PREN = 10;

int dp[PREN + 1], Q, a, b, c, d, x;

void precalc(){
    for (int i = 1; i <= PREN; i++)
    {
        int x, y;
        x = (i / a - b <= 0 ? 1 : dp[i / a - b]);
        y = (i / c - d <= 0 ? 1 : dp[i / c - d]);
        dp[i] = x + y;
    }
}

int recurse(int p){
    if(p <= 0) return 1;
    else if(p <= PREN) return dp[p];
    else {
        return recurse(p / a - b) + recurse(p / c - d);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d >> Q;
    precalc();
    cout << dp[1];

    for(size_t i = 0; i < Q; i++){
        cin >> x;
        cout << recurse(x) << "\n";
    }   
}