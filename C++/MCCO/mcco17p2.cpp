#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 200002, inf = 1 << 30;

ll seg[4 * MAXN], lazy[4 * MAXN];
int N, Q, K, t, l, r, v, p; 

void update(int ql, int qr, int v, int rl, int rr, int p) {
    if(lazy[p]) {
        seg[p] += lazy[p];
        if(rl != rr) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
    
    if(ql <= rl && rr <= qr) {
        seg[p] += v;
        if(rl != rr) {
            lazy[p * 2] += v;
            lazy[p * 2 + 1] += v;
        }
    }
    else if(rl > qr || rr < ql) return;
    else {
        int mid = (rl + rr) / 2;
        update(ql, qr, v, rl, mid, p * 2);
        update(ql, qr, v, mid + 1, rr, p * 2 + 1);
        seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
    }
}

ll query(int ql, int qr, int rl, int rr, int p) {
    if(lazy[p]) {
        seg[p] += lazy[p];
        if(rl != rr) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if(ql <= rl && rr <= qr) return seg[p];
    else if(rl > qr || rr < ql) return -inf;
    else {
        int mid = (rl + rr) / 2;
        return max(
            query(ql, qr, rl, mid, p * 2),
            query(ql, qr, mid + 1, rr, p * 2 + 1)
        );
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> t;
        if(t == 0) {
            cin >> p >> v;
            int lb = max(p - K + 1, 0);
            update(lb, p, v, 0, N + 1, 1);
        }
        else {
            cin >> l >> r;
            cout << query(l, r, 0, N + 1, 1) << "\n";
        }
    }
}