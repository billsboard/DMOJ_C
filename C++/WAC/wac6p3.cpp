#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll>> plii;
const ll MAXN = 200001;
ll inf = 1LL << 63;

ll tmp[MAXN], mx = 0, seg[4 * MAXN];
plii arr[MAXN];
unordered_map<ll, ll> idxs;
ll N;

void update(ll i, ll v, ll rl, ll rr, ll p){
    if(rl == rr) seg[p] = v;
    else {
        ll mid = (rl + rr) / 2;
        if(i <= mid) update(i, v, rl, mid, p * 2);
        else update(i, v, mid + 1, rr, p * 2 + 1);

        seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
    }
}

ll query(ll ql, ll qr, ll rl, ll rr, ll p){
    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        ll mid = (rl + rr) / 2;
        return max(query(ql, qr, rl, mid, p * 2), query(ql, qr, mid + 1, rr, p * 2 + 1));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> tmp[i];
        arr[i] = make_pair(tmp[i], make_pair(i, 0));
    }

    sort(arr, arr + N);
    
    for (size_t i = 1; i < N; i++)
    {
        arr[i].second.second = i;
        arr[i - 1].second.second = i - 1;

        idxs[arr[i - 1].first] = i - 1;
        idxs[arr[i].first] = i;
        update(i, abs(arr[i].first - arr[i - 1].first), 1, N, 1);
    }    
    
    for (ll i = N - 1; i >= 0; i--)
    {
        ll cur = tmp[i];
        plii cor = arr[i];
        if(cor.first == cur) continue;
        mx = max(query(min(idxs[cor.first], idxs[cur]) + 1, max(idxs[cor.first], idxs[cur]), 1, N ,1), mx);
        tmp[i] = cor.first;
        tmp[cor.second.first] = cur;
    }
    cout << mx << "\n";
     
}