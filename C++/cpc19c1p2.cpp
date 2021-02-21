#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 2 * 1e5, inf = 1 << 30;

int N, arr[MAXN], K, mx = 1;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    
    int l = 0, r = 1;

    while (l != r)
    {
        if(arr[r] - arr[l] <= K){
            mx = max(mx, r - l + 1);
            r++;
            if(r == N){
                r = N - 1;
                l++;
            }
        }
        else {
            l++;
            if(r == l && r < N - 1) r++;
        }
    }

    cout << mx << "\n";
}