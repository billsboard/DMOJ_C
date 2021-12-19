#include <iostream>

using namespace std;
const int MAXR = 2001;

int seg[MAXR][4 * MAXR + 4], N, r, c, u, v, t, d, cnt = 0;

void update(int x, int i, int v, int rl, int rr, int p) {
    if(rl == rr) {
        seg[x][p] += v;
    }
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid) {
            update(x, i, v, rl, mid, p * 2);
        }
        else {
            update(x, i, v, mid + 1, rr, p * 2 + 1);
        }

        seg[x][p] = seg[x][p * 2] + seg[x][p * 2 + 1];
    }
}

int query(int x, int ql, int qr, int rl, int rr, int p) {
    if(ql <= rl && rr <= qr) return seg[x][p];
    else if(rl > qr || rr < ql) return 0;
    else {
        int mid = (rl + rr) / 2;
        return query(x, ql, qr, rl, mid, p * 2) + 
            query(x, ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> d;
        if(d == 1) {
            cin >> r >> c >> t;
            u = r + c - 1;
            update(u, r, t, 1, MAXR, 1);
        }
        else {
            cin >> r >> c >> t;
            u = r + c - 1;
            cnt += query(u, r - t, r, 1, MAXR, 1);
        }
    }

    cout << cnt << "\n"; 
}