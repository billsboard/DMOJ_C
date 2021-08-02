#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 100001;

int psa[3][MAXN], N, Q, l, r, x;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> x;
        psa[0][i] = psa[0][i - 1];
        psa[1][i] = psa[1][i - 1];
        psa[2][i] = psa[2][i - 1];

        psa[x - 1][i]++;
    }

    while (Q--)
    {
        cin >> l >> r;
        cout << psa[0][r] - psa[0][l - 1] << " " << psa[1][r] - psa[1][l - 1] << " " << psa[2][r] - psa[2][l - 1] << "\n";
    }
}