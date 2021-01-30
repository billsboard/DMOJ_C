#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1000001, inf = 1 << 30;

int arr[MAXN], N, cnt = -inf, v = -1, mx = -inf, mxv = -1;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    arr[N] = inf;

    sort(arr, arr + N + 1);
    for (size_t i = 0; i <= N; i++)
    {
        if(arr[i] != v){
            if(cnt > mx){
                mxv = v;
                mx = cnt;
            }
            v = arr[i];
            cnt = v;
        }
        else cnt += arr[i];
    }

    cout << mxv << "\n";
}