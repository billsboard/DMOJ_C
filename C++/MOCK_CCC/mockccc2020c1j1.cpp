#include <iostream>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 5, inf = 1 << 30;
const pii none = make_pair(-inf, inf);

int arr[MAXN], N = 4;
pii seg[4 * MAXN];

void build(int rl, int rr, int p){
    if(rl == rr) seg[p] = make_pair(arr[rl], arr[rl]);
    else {
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
        seg[p] = make_pair(max(seg[p * 2].first, seg[p * 2 + 1].first), min(seg[p * 2].second, seg[p * 2 + 1].second));
    }
}

void update(int i, int v, int rl, int rr, int p){
    if(rl == rr) seg[p] = make_pair(v, v);
    else{
        int mid = (rl + rr) / 2;
        if(i <= mid) update(i, v, rl, mid, p * 2);
        else update(i, v, mid + 1, rr, p * 2 + 1);
        seg[p] = make_pair(max(seg[p * 2].first, seg[p * 2 + 1].first), min(seg[p * 2].second, seg[p * 2 + 1].second));
    }
}

pii query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return none;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        pii a = query(ql, qr, rl, mid, p * 2), b = query(ql, qr, mid + 1, rr, p * 2 + 1);
        return make_pair(max(a.first, b.first), min(a.second, b.second));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    build(1, N, 1);

    pii res = query(1, N, 1, N, 1);
    cout << res.second << "\n" << res.first << "\n";
}