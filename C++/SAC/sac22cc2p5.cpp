#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 500001;


struct seg {
    ll seg[MAXN * 4 + 4], arr[MAXN];

    void build(int l, int r, int p) {
        if(l == r) seg[p] = arr[l];
        else {
            int mid = (l + r) / 2;
            build(l, mid, p * 2);
            build(mid + 1, r, p * 2 + 1);
            seg[p] = seg[p * 2] + seg[p * 2 + 1];
        }
    }

    void update(int i, ll v, int rl, int rr, int p) {
        if(rl == rr){
            seg[p] = v;
        }
        else {
            int mid = (rl + rr) / 2;
            if(i <= mid) update(i, v, rl, mid, p * 2);
            else update(i, v, mid + 1, rr, p * 2 + 1);
            seg[p] = seg[p * 2] + seg[p * 2 + 1];
        }
    }

    ll query(int ql, int qr, int rl, int rr, int p) {
        if(ql <= rl && rr <= qr) return seg[p];
        else if(rl > qr || rr < ql) return 0;
        else {
            int mid = (rl + rr) / 2;
            return query(ql, qr, rl, mid, p * 2) + query(ql, qr, mid + 1, rr, p * 2 + 1);
        }
    }
};

seg O, E;
int N, Q, o, e, t, x, L, R;
ll v;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (size_t i = 1; i <= N; i++)
    {
        if(i & 1) {
            cin >> O.arr[i / 2 + 1];
            o++;
        }
        else {
            cin >> E.arr[i / 2];
            e++;
        }
    }
    
    O.build(1, o, 1); E.build(1, e, 1);

    for (size_t i = 0; i < Q; i++)
    {
        cin >> t;
        if(t == 1) {
            cin >> x >> v;
            if(x & 1) O.update(x / 2 + 1, v, 1, o, 1);
            else E.update(x / 2, v, 1, e, 1);
        }
        else if(t == 2) {
            cin >> L >> R;
            if(L & 1) {
                if(!(R & 1)) R--;
                cout << O.query(L / 2 + 1, R / 2 + 1, 1, o, 1) << "\n";
            }
            else {
                if(R & 1) R--;
                cout << E.query(L / 2, R / 2, 1, e, 1) << "\n";
            }
        }
    }
}