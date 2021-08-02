#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXN = 100000;

int arr[MAXN], N, K;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N, greater<int>());
    ll cnt = 0;
    for (size_t i = 0; i < K; i++)
    {
        cnt += arr[i];
    }
    cout << cnt << "\n";
}