#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 200002;

int N, M, a, b;
ll seg[4 * MAXN], lazy[4 * MAXN], K;
bool found = false;

void update(int ql, int qr, int v, int rl, int rr, int p) {
    if(lazy[p]) {
        seg[p] += lazy[p] * (rr - rl + 1);
        if(rl != rr) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if(ql <= rl && rr <= qr) {
        seg[p] += v * (rr - rl + 1);
        if(rl != rr) {
            lazy[p * 2] += v;
            lazy[p * 2 + 1] += v;
        }
    }
    else if(rr < ql || rl > qr) return;
    else {
        int mid = (rl + rr) / 2;
        update(ql, qr, v, rl, mid, p * 2);
        update(ql, qr, v, mid + 1, rr, p * 2 + 1);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

ll query(int ql, int qr, int rl, int rr, int p) {
    if(lazy[p]) {
        seg[p] += lazy[p] * (rr - rl + 1);
        if(rl != rr) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if(ql <= rl && rr <= qr) return seg[p];
    else if(rr < ql || rl > qr) return 0;
    else {
        int mid = (rl + rr) / 2;
        return query(ql, qr, rl, mid, p * 2) + query(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}



bool ok(int W) {
    for (size_t i = 1; i <= N; i++)
    {
        if(i + W - 1 > N) break;
        if(query(i, i + W - 1, 1, N, 1) >= K) {
            found = true;
            return true;
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    if(K == 0) {
        cout << 0 << "\n";
        return 0;
    }

    for (size_t i = 1; i <= M; i++)
    {
        update(i, i, M, 1, N, 1);
        cin >> a >> b;
        update(a, b, -1, 1, N, 1);
    }

    int l = 1, r = N + 1, mid;
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
    
    cout << (found ? r + 1 : -1) << "\n";
}