#include <iostream>

using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 1, inf = 1 << 30;

struct node {
    ll pre, suf, sum, sub;
};

int arr[MAXN], N;
node seg[4 * MAXN], none = {inf, 0, 0, 0};

node combine(node l, node r){
    if(r.pre == inf && l.pre == inf) return none;
    else if(l.pre == inf) return r;
    else if(r.pre == inf) return l;

    node n;
    n.sum = l.sum + r.sum;
    n.pre = max(l.pre, l.sum + r.pre);
    n.suf = max(r.suf, r.sum + l.suf);
    n.sub = max(
        max(l.sub, r.sub),
        max(l.suf + r.pre, l.sum + r.sum));
    return n;
}

void build(int rl, int rr, int p){
    if(rl == rr) {
        node n;
        n.sum = arr[rl];
        n.pre = n.sum;
        n.suf = n.sum;
        n.sub = n.sum;
        seg[p] = n;
    }
    else {
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }
}

node query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return none;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) / 2;
        return combine(query(ql, qr, rl, mid, p * 2),
            query(ql, qr, mid + 1, rr, p * 2 + 1));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        if(arr[i] & 1) arr[i] = -inf;
    }
    
    build(1, N, 1);
    cout << query(1, N, 1, N, 1).sub << "\n";
}