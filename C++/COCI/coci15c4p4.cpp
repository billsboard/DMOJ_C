#include <iostream>

using namespace std;
typedef long long ll;

int K, Q;
ll N, x, y;

int main(void){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        int cnt = 0;
        cin >> x >> y;
        while (x != y)
        {
            if(x >= y) x = (x + K - 2) / K;
            else y = (y + K - 2) / K;
            cnt++;
        }
        cout << cnt << "\n";
    }   
}