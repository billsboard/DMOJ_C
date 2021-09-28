#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 200000 + 1;

int arr[MAXN], N;
ll psa[MAXN], M;
bool found = false;

bool ok(int l) {
    for (size_t i = 1; i <= N; i++)
    {
        if(i + l - 1 > N) break;
        if(psa[i + l - 1] - psa[i - 1] < M) {
            found = true;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        psa[i] = arr[i] + psa[i - 1];
    }

    int l = 1, r = N + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if(ok(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << (found ? r : 0) << "\n";
}