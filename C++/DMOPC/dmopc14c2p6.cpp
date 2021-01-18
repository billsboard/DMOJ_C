#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100001, MAXQ = 100001;

struct val {
    int v, i;
    bool operator < (const val& b){
        return v > b.v;
    }
};

struct qur {
    int l, r, q, i;
    bool operator < (const qur& b){
        return q > b.q;
    }
};

int offline[MAXQ], seg[4 * MAXN], N, Q, v, l, r, q, idx = 0;
qur qurs[MAXQ];
val vals[MAXN];

void update(int i, int v, int rl, int rr, int p){
    if(rl == rr) seg[p] = v;
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid){
            update(i, v, rl, mid, p * 2);
        }
        else {
            update(i, v, mid + 1, rr, p * 2 + 1);
        }
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int ql, int qr, int rl, int rr, int p){
    if(rr < ql || rl > qr) return 0;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        return query(ql, qr, rl, mid, p * 2) + query(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> v;
        vals[i] = {v, i + 1};
    }

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> l >> r >> q;
        qurs[i] = {l + 1, r + 1, q, i};
    }

    sort(vals, vals + N);
    sort(qurs, qurs + Q);

    for (size_t i = 0; i < Q; i++)
    {
        qur cur = qurs[i];
        while (idx < N && vals[idx].v >= cur.q)
        {
            update(vals[idx].i, vals[idx].v, 1, N, 1);
            idx++;
        }
        offline[cur.i] = query(cur.l, cur.r, 1, N, 1);
    }
    
    for (size_t i = 0; i < Q; i++)
    {
        cout << offline[i] << "\n";
    }
}
