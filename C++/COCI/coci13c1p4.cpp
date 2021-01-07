#include <iostream>
#include <set>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 300001, MAXV = 300003;
const pii none = make_pair(-1, -1);
pii seg[1048576];
int N, K, m, v, c, coord[MAXN], sorted[MAXN], tempV[MAXN], tempM[MAXN];
long long res = 0;
priority_queue<int, vector<int>, greater<int>> bags;
priority_queue<int, vector<int>> arr[MAXV + 1];
set<pii> auxSet;

pii combine(pii left, pii right){
    if(left.second > right.second)
        return left;
    return right;
}

void build(int rl, int rr, int p){
    if(rl == rr) {
        if(arr[rl].empty()) seg[p] = none;
        else seg[p] = make_pair(rl, arr[rl].top());
    }
    else {
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }
}

void update(int i, int rl, int rr, int p){
    if(rl == rr){
        if(arr[rl].empty()) seg[p] = none;
        else seg[p] = make_pair(rl, arr[rl].top());
    }
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid)
            update(i, rl, mid, p * 2);
        else
            update(i, mid + 1, rr, p * 2 + 1);
        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }
}

pii query(int ql, int qr, int rl, int rr, int p){
    if(rr < ql || rl > qr) return none;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) / 2;
        return combine(
            query(ql, qr, rl, mid, p * 2), query(ql, qr, mid + 1, rr, p * 2 + 1)
        );
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> coord[i] >> tempV[i];
        sorted[i] = coord[i];
        tempM[i] = coord[i];
    }

    sort(sorted, sorted + N);
    for (size_t i = 0; i < N; i++)
    {
        int comp = lower_bound(sorted, sorted + N, coord[i]) - sorted + 1;
        auxSet.insert(make_pair(tempM[i], comp));
        coord[i] = comp;
    }
    

    for (size_t i = 0; i < N; i++)
    {
        arr[coord[i]].push(tempV[i]);
    }

    for (size_t i = 0; i < K; i++)
    {
        cin >> c;
        bags.push(c);
    }

    build(1, MAXV, 1);

    while (!bags.empty())
    {
        int cap = min(bags.top(), 1000000);
        bags.pop();

        int compCap = (*--auxSet.upper_bound(make_pair(cap, 1 << 30))).second;

        pii qRes = query(1, compCap, 1, MAXV, 1);
        if(qRes.first == -1) continue;

        res += qRes.second;
        arr[qRes.first].pop();
        update(qRes.first, 1, MAXV, 1);
    }

    cout << res << "\n";
}