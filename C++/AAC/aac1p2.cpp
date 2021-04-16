#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 1;

double d;
ll N, D, K, X, P, arr[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D >> K >> X;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> P;

    d = (100.0 - X) / 100.0; 

    sort(arr, arr + N);
    int cnt = 0, idx = 0;
    while (cnt < K)
    {
        if(idx >= N) break;
        
        if(arr[idx] < P) {
            idx++;
        }
        else {
            cnt++;
            arr[idx] *= d;
        }
    }
    

    for (size_t i = 0; i < N; i++)
    {
        if(arr[i] >= P) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}

