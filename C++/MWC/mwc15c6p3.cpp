#include <iostream>
#include <bitset>

using namespace std;
const int MAXN = 1001, MAXI = 61;
typedef bitset<MAXI> bs;

int N, Q, S, x;
bs arr[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> S;
        for (size_t j = 0; j < S; j++)
        {
            cin >> x;
            arr[i][x + 30] = 1;
        }
    }
    for (size_t i = 0; i < Q; i++)
    {
        cin >> S;
        bs res;
        for (size_t j = 0; j < S; j++)
        {
            cin >> x;
            res ^= arr[x];
        }
        cout << res.count();
        for (size_t j = 0; j < MAXI; j++)
        {
            if(res[j]) cout << " " << (j - 30);
        }
        cout << "\n";
    }
}
