#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 10001, MAXT = 1001, inf = 1 << 30;

struct person{
    int v, s, t;
};

struct compareTo{
    bool operator()(const person& a, const person& b){
        if(a.t == b.t) return a.s < b.s;
        return a.t < b.t;
    }
};

int dp[MAXT], new_dp[MAXT], N, T, v, s, t;
person arr[MAXN];

int main(){
    cin.sync_with_stdio();
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> v >> s >> t;
        arr[i] = {v, s, t};
    }

    sort(arr + 1, arr + N + 1, compareTo());

    for (size_t i = 1; i < MAXT; i++)
    {
        if(i >= arr[1].s && i <= arr[1].t) dp[i] = arr[1].v;
    }

    for (int i = 2; i <= N; i++)
    {
        new_dp[0] = 0;
        dp[0] = 0;
        for (int j = 1; j < MAXT; j++)
        {
            new_dp[j] = dp[j];
            if(j >= arr[i].s && j <= arr[i].t) {
                new_dp[j] = max(dp[j], dp[j - arr[i].s] + arr[i].v);
            }
        }
        swap(new_dp, dp);
    }

    int mx = 1 << 31;
    for(int i = 1; i < MAXT; i++){
        mx = max(mx, dp[i]);
    }
    
    cout << mx << "\n";
}
