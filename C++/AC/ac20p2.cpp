#include <iostream>

using namespace std;
const int MAXA = 1e5 + 1;
typedef long long ll;

ll arr[MAXA];
int N, Q, t, x;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        arr[x]++;
    }

    for (size_t i = 0; i < Q; i++)
    {
        cin >> t >> x;
        if(t == 1){
            ll cnt = arr[x];
            arr[x] = 0;
            if(x & 1){
                arr[x / 2 + 1] += cnt;
                arr[x / 2] += cnt;
            }
            else {
                arr[x / 2] += 2 * cnt;
            }
        }
        else if(t == 2){
            cout << arr[x] << "\n";
        }
    }
}