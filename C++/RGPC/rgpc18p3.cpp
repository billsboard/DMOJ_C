#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 2;

int N, T, L, a, b, c;
ll diff[MAXN], psa[MAXN], cnt;

bool ok(int l) {
    for (size_t i = 1; i <= N; i++)
    {
        if(i + l - 1 > N) break;
        if(psa[i + l - 1] - psa[i - 1] <= L) return true;
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> a >> b >> c;
        diff[a] += c;
        diff[b + 1] -= c;
    }

    for (size_t i = 1; i <= N; i++)
    {
        cnt += diff[i];
        psa[i] = psa[i - 1] + cnt;
    }

    cin >> L;

    int l = 1, r = N + 1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << r << "\n";
}