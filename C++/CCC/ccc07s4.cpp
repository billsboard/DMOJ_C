#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 10000;

int N, x, y, dp[MAXN];
vector<int> adj[MAXN];

void recurse(int p, int v){ 
    if(v == 1) dp[1] = 1;
    else if(dp[v] == 0){
        for (int x : adj[v])
        {
            recurse(v, x);
            dp[v] += dp[x];
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (true)
    {
       cin >> x >> y;
       if(x == 0 && y == 0) break;
       adj[y].push_back(x);
    }
    
    dp[1] = 1;
    recurse(0, N);
    cout << dp[N] << "\n";
}