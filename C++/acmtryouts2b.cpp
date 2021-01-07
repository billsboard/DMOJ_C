#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MAXL = 1001;
ll seg[MAXL * 4], lazy[MAXL * 4];
int L, N, M, T, c, r, d, h;

void update(int ql, int qr, int v, int rl, int rr, int p){
    if(lazy[p]){
        seg[p] += (rr - rl + 1) * lazy[p];
        if(rl != rr){
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if(rl > qr || rr < ql) return;
    else if(ql <= rl && rr <= qr) {
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

ll query(int ql, int qr, int rl, int rr, int p){
    if(lazy[p]){
        seg[p] += (rr - rl + 1) * lazy[p];
        if(rl != rr){
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) {
        return seg[p];
    }
    else {
        int mid = (rl + rr) / 2;
        return query(ql, qr, rl, mid, p * 2) + query(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        fill(&seg[0], &seg[0] + sizeof(seg) / sizeof(ll), 0);
        fill(&lazy[0], &lazy[0] + sizeof(lazy) / sizeof(ll), 0);
        cin >> L >> N;
        for (size_t j = 0; j < N; j++)
        {
            cin >> c >> r >> d;
            update(max(1, c - r), min(L, c + r), d, 1, MAXL, 1);
        }

        cin >> M;
        for (size_t j = 0; j < M; j++)
        {
            cin >> h;
            for (size_t i = 1; i <= L; i++)
            {
                h -= query(i, i, 1, MAXL, 1);
                if(h <= 0){
                    cout << i << "\n";
                    goto loop;
                }
            }
            cout << "Bloon leakage\n";
            
            loop:;
        }
    }
}