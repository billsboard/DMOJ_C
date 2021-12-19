#include <iostream>

using namespace std;
typedef long long ll;

ll N, K, amt = 1, cnt = 0;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    while (amt < N)
    {
        if(amt < K) amt *= 2;
        else {
            cnt += ((N - amt) + (K - 1)) / K;
            break;
        }
        cnt++;
    }

    cout << cnt << "\n";
}