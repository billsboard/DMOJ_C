#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1001;

int arr[MAXN], dp[MAXN], N, T, mn = 1 << 30;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1);
    
    for(int i = 1; i < N; i++){
        if(i + T - 1 > N) break;
        int a = arr[i], b = arr[i + T - 1];
        if(a < 0 && b <= 0){
            mn = min(-a, mn);
        }
        else if(a < 0 && b > 0){
            mn = min(-a * 2 + b, mn);
            mn = min(b * 2 + -a, mn);
        }
        else{
            mn = min(b, mn);
        }
    }

    cout << mn << "\n";
}