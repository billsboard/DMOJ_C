#include <iostream>

using namespace std;
typedef long long ll;
const int MAXK = 100001;

ll psa[MAXK];
int K, Q;
ll a, b, x;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    for (size_t i = 1; i <= K; i++)
    {
        cin >> x;
        psa[i] = psa[i - 1] ^ x;
    }

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> a >> b;
        cout << (psa[(a - 1) % (K + 1)] ^ psa[b % (K + 1)]) << "\n";
    }
}