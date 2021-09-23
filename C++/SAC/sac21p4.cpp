#include <iostream>

using namespace std;
const int MAXN = 1000001;

int seg[MAXN * 4], arr[MAXN], N, Q, l, r;

void build(int rl, int rr, int p){
    if(rl == rr) seg[p] = arr[rl];
    else {
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
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

    cin >> N >> Q;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    
    build(1, N, 1);
    for (size_t i = 0; i < Q; i++)
    {
        cin >> l >> r;
        cout << query(l, r, 1, N, 1) / (r - l + 1) << "\n";
    }
    
}