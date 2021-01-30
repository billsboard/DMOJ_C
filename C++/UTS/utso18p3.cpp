#include <iostream>
#include <utility>

using namespace std;
const int MAXN = 1e6 + 1;
typedef pair<int, int> pii;
const pii none = make_pair(0, -1);

int N, T, K, V, arr[MAXN], x, cnt = 0;
pii seg[4 * MAXN];

pii combine(pii a, pii b){
    return make_pair(a.first + b.first, max(a.second, b.second));
}

void build(int rl, int rr, int p){
    if(rl == rr){
        pii s;
        s.first = arr[rl];
        if(arr[rl] == 0) s.second = rl;
        else s.second = -1;
        seg[p] = s; 
    }
    else{
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }
}

void update(int i, int rl, int rr, int p){
    if(rl == rr){
        seg[p] = make_pair(1, -1);
    }
    else{
        int mid = (rl + rr) / 2;
        if(i <= mid) update(i, rl, mid, p * 2);
        else update(i, mid + 1, rr, p * 2 + 1);
        seg[p] = combine(seg[p * 2], seg[p * 2 + 1]);
    }
}

pii query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return none;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        return combine(query(ql, qr, rl, mid, p * 2), query(ql, qr, mid + 1, rr, p * 2 + 1));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T >> K >> V;
    for (size_t i = 0; i < V; i++)
    {
        cin >> x;
        arr[x] = 1;
    }

    build(1, N, 1);

    for (size_t i = 1; i <= N; i++)
    {
        if(i + T - 1 > N) break;
        pii res = query(i, i + T - 1, 1, N, 1);
        while (res.first < K)
        {
            update(res.second, 1, N, 1);
            cnt++;
            res = query(i, i + T - 1, 1, N, 1);
        }
    }
    cout << cnt << "\n";
}
