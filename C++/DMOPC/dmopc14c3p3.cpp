#include <iostream>
#include <string>

using namespace std;
const int MAXN = 500, inf = 1 << 30;

string arr[MAXN];
int S[MAXN], N, Q, d, s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i] >> S[i];
    }

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> s >> d;
        int mn = inf; string res = "ki";
        for (size_t j = 0; j < N; j++)
        {
            if(s > S[j]) continue;
            if(S[j] - s < mn) {
                res = arr[j];
                mn = abs(s - S[j]);
            }
        }

        if(mn > d) cout << "No suitable teacher!\n";
        else cout << res << "\n";
    }
}