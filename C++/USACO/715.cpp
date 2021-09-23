#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100001, inf = 1 << 30;

int N, K, B, x;
int arr[MAXN], psa[MAXN];

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> B;
    fill(&arr[0], &arr[0] + sizeof(arr) / sizeof(arr[0]), 1);

    while (B--)
    {
        cin >> x;
        arr[x] = 0;
    }

    for (size_t i = 1; i <= N; i++)
    {
        psa[i] = psa[i - 1] + arr[i];
    }
    
    int mn = inf;
    for (size_t i = 1; i <= N; i++)
    {
        if(i + K - 1 > N) break;
        mn = min(mn, K - (psa[i + K - 1] - psa[i - 1]));
    }

    cout << mn << "\n";
}