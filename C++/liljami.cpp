#include <iostream>

using namespace std;
const int MAXN = 1000001;

int seg[4 * MAXN], N, K, Q, x, y;

void update(int i, int v, int rl, int rr, int p){
    if(rl == rr) seg[p] += v;
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid) update(i, v, rl, mid, p * 2);
        else update(i, v, mid + 1, rr, p * 2 + 1);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) / 2;
        return query(ql, qr, rl, mid, p * 2) + query(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < K; i++)
    {
        cin >> x;
        update(x + 1, 1, 1, N, 1);
    }

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x >> y;
        cout << query(x + 1, y + 1, 1, N, 1) << "\n";
    }
}