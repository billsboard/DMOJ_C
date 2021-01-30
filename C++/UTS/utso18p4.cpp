#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 2 * 1e5 + 1, MAXV = 1e5 + 1, inf = 1 << 30;

struct coupon{
    ll c, m, v;
    coupon(ll _c, ll _m){
        c = _c;
        m = _m;
        v = c + m;
    }
    coupon(){}
};

struct compareTo{
    bool operator()(const coupon& a, const coupon& b){
        return a.c < b.c;
    }
};

coupon arr[MAXN], psa[MAXN];
vector<coupon> vals[MAXV];
int N;
ll mx = -inf, c, m;

coupon query(int l, int r){
    if(l > r) return coupon(-inf, -inf);
    else if(l == 0) return psa[r];
    else return coupon(psa[r].c - psa[l - 1].c, psa[r].m - psa[l - 1].m);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> c >> m;
        vals[c + m].push_back(coupon(c, m));
    }

    for (size_t i = 1; i < MAXV; i++)
    {
        if(vals[i].size() <= 1) {
            mx = max(mx, 0LL);
            continue;
        }
        sort(vals[i].begin(), vals[i].end(), compareTo());

        psa[0] = coupon(vals[i][0].c, vals[i][0].m);
        for(int j = 1; j < vals[i].size(); j++){
            psa[j] = coupon(psa[j - 1].c + vals[i][j].c, psa[j - 1].m + vals[i][j].m);
        }

        for (size_t j = 0; j < vals[i].size(); j++)
        {
            mx = max(min(query(0, j).m, query(j + 1, vals[i].size() - 1).c), mx);
        }
    }
    cout << mx << "\n";
}