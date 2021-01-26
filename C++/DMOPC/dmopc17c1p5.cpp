#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e6 + 1, MAXQ = 1e6 + 1, inf = 1 << 30;

struct input {
    int l, r, i;
    input(int _l, int _r, int _i){
        l = _l;
        r = _r;
        i = _i;
    }
    input(){}
    bool operator< (const input& o){
        if(l == o.l) return r < o.r;
        return l < o.l;
    }
};

input in[MAXQ];
int seg[4 * MAXN], arr[MAXN], offline[MAXN], N, Q, l, r, idx = 1;
pii blk[MAXN];
stack<pii> stk;

void update(int i, int rl, int rr, int p){
    if(rl == rr) seg[p] += 1;
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid) update(i, rl, mid, p * 2);
        else update(i, mid + 1, rr, p * 2 + 1);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        return query(ql, qr, rl, mid, p * 2) + query(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

bool compareTo(const pii& a, const pii& b){
    return a.first < b.first;
}

void pushStk(pii p){
    while (!stk.empty() && stk.top().second < p.second)
    {
        stk.pop();
    }
    blk[p.first] = make_pair(stk.top().first + 1, p.first);
    stk.push(p);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    stk.push(make_pair(0, inf));
    cin >> N >> Q;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    for (size_t i = 1; i <= N; i++){
        pushStk(make_pair(i, arr[i]));
    }

    for (size_t i = 0; i < Q; i++)
    {
        cin >> l >> r;
        in[i] = {l, r, i};
    }

    sort(in, in + Q);
    sort(blk + 1, blk + N + 1, compareTo);

    for (size_t i = 0; i < Q; i++)
    {
        input qur = in[i];
        while (idx <= N && blk[idx].first <= qur.l)
        {
            update(blk[idx].second, 1, N ,1);
            idx++;
        }
        offline[qur.i] = query(qur.l, qur.r, 1, N, 1);
    }

    for (size_t i = 0; i < Q; i++)
    {
        cout << offline[i] << "\n";
    }
}