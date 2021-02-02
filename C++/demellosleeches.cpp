#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 200001, inf = 1 << 30;

int arr[MAXN], lazy[4 * MAXN], N, Q, cnt = 0, l, r;
pii seg[4 * MAXN], none = make_pair(inf, -1);

void build(int rl, int rr, int p){
    if(rl == rr) seg[p] = make_pair(arr[rl], rl);
    else{
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }
}

void update(int ql, int qr, int v, int rl, int rr, int p){
    if(lazy[p]){
        if(rl != rr){
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        seg[p].first += lazy[p];
        lazy[p] = 0;
    }

    if(rl > qr || rr < ql) return;
    else if(ql <= rl && rr <= qr){
        seg[p].first += v;
        if(rl != rr){
            lazy[p * 2] += v;
            lazy[p * 2 + 1] += v;
        }
    }
    else{
        int mid = (rl + rr) / 2;
        update(ql, qr, v, rl, mid, p * 2);
        update(ql, qr, v, mid + 1, rr, p * 2 + 1);
        seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
    }
}


pii query(int ql, int qr, int rl, int rr, int p){
    if(lazy[p]){
        if(rl != rr){
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        seg[p].first += lazy[p];
        lazy[p] = 0;
    }

    if(rl > qr || rr < ql) return none;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        return min(query(ql, qr, rl, mid, p * 2), query(ql, qr, mid + 1, rr, p * 2 + 1));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    build(1, N, 1);

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> l >> r;
        update(l, r, -1, 1, N, 1);
        pii res = query(l, r, 1, N, 1);
        cnt = 0;
        while (res.first < 0)
        {
            cnt++;
            update(res.second, res.second, inf, 1, N, 1);
            res = query(l, r, 1, N, 1);
        }
        cout << cnt << "\n";
    }
}