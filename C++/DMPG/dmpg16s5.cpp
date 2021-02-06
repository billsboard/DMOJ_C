#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 100001;
const ll inf = 1LL << 62;

struct segment{
    ll pre, suf, sum, sub;
    bool blank = false;
    segment(ll _v){
        pre = _v;
        suf = _v;
        sum = _v;
        sub = _v;
    }
    segment(){}
    segment(bool fail, bool fail2){
        blank = true;
    }
    segment(ll _pre, ll _suf, ll _sum, ll _sub){
        pre = _pre;
        suf = _suf;
        sum = _sum;
        sub = _sub;
    }
};

int N, M, K;
ll arr[2 * MAXN];
ll mx = -inf;
segment seg[4 * MAXN * 2];
const segment none = segment(true, true);

segment combine(const segment& l, const segment& r){
    if(l.blank && r.blank) return none;
    else if(r.blank){
        return segment(l.pre, l.suf, l.sum, l.sub);
    }
    else if(l.blank){
        return segment(r.pre, r.suf, r.sum, r.sub);
    }
    else{
        segment s;
        s.sum = l.sum + r.sum;
        s.pre = max(l.pre, l.sum + r.pre);
        s.suf = max(r.suf, l.suf + r.sum);
        s.sub = max(max(l.sub, r.sub), l.suf + r.pre);
        return s;
    }
}

void build(int rl, int rr, int p){
    if(rl == rr) seg[p] = segment(arr[rl]);
    else{
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }
}

segment query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return none;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) / 2;
        return combine(query(ql, qr, rl, mid, p * 2), query(ql, qr, mid + 1, rr, p * 2 + 1));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    M = 2 * N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i + N] = arr[i];
    }
    arr[2 * N + 1] = -inf;

    build(1, M, 1);
    
    for (size_t i = 1; i <= M; i++)
    {
        if(i + K > M + 1) break;
        segment res = query(i, i + K - 1, 1, M, 1);
        mx = max(mx, res.sub);
    }
    cout << mx << "\n";
}