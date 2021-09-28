#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAXN = 200001;

int arr[MAXN], freq[MAXN], seg[2 * MAXN], req[MAXN], N, R, K, x, y;
bool found = false;

void build() { 
  for (int i = N - 1; i > 0; --i) seg[i] = max(seg[i<<1], seg[i<<1|1]);
}

void update(int p, int value) { 
  for (seg[p += N] += value; p > 1; p >>= 1) seg[p>>1] = max(seg[p], seg[p^1]);
}

int query(int l, int r) {
  int res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(seg[l++], res);
    if (r&1) res = max(seg[--r], res);
  }
  return res;
}

bool ok(int l) {
    memset(seg, 0, sizeof(seg));
    for (size_t i = 0; i < N; i++)
    {
        seg[i + N] = req[i];
    }
    build();

    int cl = 0, i = 0;
    while (i < N)
    {
        cl++;
        update(arr[i], -1);
        if(cl > l) update(arr[i - l], 1);

        if(query(0, N) <= 0) {
            found = true;
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> R;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (size_t i = 0; i < R; i++)
    {
        cin >> x >> y;
        req[x] += y;
    }
    

    int l = 0, r = N, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if(ok(mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    
    if(found) {
        cout << l << "\n";
    }
    else {
        cout << "impossible\n";
    }
}