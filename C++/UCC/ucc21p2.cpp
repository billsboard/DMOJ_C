#include <iostream>

using namespace std;
const int inf = 1 << 30;

int N, x, mx = -inf, cnt = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        if(x & 1){
            mx = max(mx, cnt);
            cnt = 0;
        }
        else {
            cnt += x;
        }
    }

    cout << max(mx, cnt) << "\n";
}

