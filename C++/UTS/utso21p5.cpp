#include <iostream>
#include <utility>

using namespace std;
const int MAXN = 5e5 + 1;
typedef long long ll;
typedef pair<int, int> pii;

struct segtree{
    
};


ll arr[MAXN], N, M, Q, l, r, x, t, bld[MAXN], idx = 2;
ll fen[MAXN][MAXN][4];
segtree seg1;

ll seg[MAXN * 4 + 4], lazy[MAXN * 4 + 4];
    
    
    void update(int ql, int qr, ll v, int rl, int rr, int p){
        if(lazy[p]){
            if(rl != rr){
                lazy[p * 2] += lazy[p];
                lazy[p * 2 + 1] += lazy[p];
            }
            seg[p] += (rr - rl + 1) * lazy[p];
            lazy[p] = 0;
        }

        if(rl > qr || rr < ql) return;
        else if(ql <= rl && rr <= qr){
            seg[p] += (rr - rl + 1) * v;
            if(rl != rr){
                lazy[p * 2] += v;
                lazy[p * 2 + 1] += v;
            }
        }
        else {
            int mid = (rl + rr) / 2;
            update(ql, qr, v, rl, mid, p * 2);
            update(ql, qr, v, mid + 1, rr, p * 2 + 1);
            seg[p] = seg[p * 2] + seg[p * 2 + 1];
        }
    }

    int query(int ql, int qr, int rl, int rr, int p){
        if(lazy[p]){
            if(rl != rr){
                lazy[p * 2] += lazy[p];
                lazy[p * 2 + 1] += lazy[p];
            }
            seg[p] += (rr - rl + 1) * lazy[p];
            lazy[p] = 0;
        }

        if(rl > qr || rr < ql) return 0;
        else if(ql <= rl && rr <= qr){
            return seg[p];
        }
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
        bld[i] = arr[i] * MAXN;
    }
    for (size_t i = 0; i < Q; i++)
    {
        cin >> t;
        if(t == 1){
            cin >> l >> r >> x;
            
            idx++;
        }
        else if(t == 2){
            cin >> l >> r;
            //seg.update(l, r, 1, N, 1);
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        //ll money = query(i, 1, i, MAXN);
        //int pays = seg.query(i, i, 1, N, 1);
        money -= (MAXN - pays) * arr[i];
        cout << money << " ";
    }
    
    
    
}
