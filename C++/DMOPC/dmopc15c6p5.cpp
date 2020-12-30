#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

const int MAXN = 3 * 1e6 + 1, inf = 1 << 30;
int arr[MAXN], N, K, maxV = -inf, minV = inf;
long long cnt = 0;
pii seg[4 * MAXN], none = make_pair(-inf, inf); // Max and Min;

void build(int rl, int rr, int p){
    if(rl == rr) seg[p] = make_pair(arr[rl], arr[rl]);
    else{
        int mid = (rl + rr) >> 1;
        build(rl, mid, p << 1);
        build(mid + 1, rr, (p << 1) + 1);
        seg[p] = make_pair(
            max(seg[(p << 1)].first, seg[(p << 1) + 1].first),
            min(seg[(p << 1)].second, seg[(p << 1) + 1].second)
        );
    }
}

pii query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return none;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) >> 1;
        pii l = query(ql, qr, rl, mid, (p << 1)), r = query(ql, qr, mid + 1, rr, (p << 1) + 1);
        return make_pair(
            max(l.first, r.first),
            min(l.second, r.second)
        );
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    build(1, N, 1);
    for (size_t l = 1, r = 1; r <= N; r++)
    {
        while (l < r)
        {
            pii res = query(l, r, 1, N, 1);
            if(res.first - res.second <= K) break;
            l++;
        }
        cnt += r - l + 1;
    }
    
    cout << cnt << "\n";
}