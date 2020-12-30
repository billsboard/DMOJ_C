#include <iostream>

using namespace std;

const int MAXN = 1e6, MAXH = 1e6 + 1, inf = 1 << 30;
int arr[MAXN + 1], seg[MAXH * 4 + 4], N, h, res;

void update(int i, int v, int rl, int rr, int p){
    if(rl == rr) seg[p] = v;
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid)
            update(i, v, rl, mid, p * 2);
        else
            update(i, v, mid + 1, rr, p * 2 + 1);
        seg[p] = max(seg[p * 2], seg[p * 2 + 1]);        
    }
}

int query(int ql, int qr, int rl, int rr, int p){
    if(rr < ql || rl > qr) return -inf;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        return max(query(ql, qr, rl, mid, p * 2), query(ql, qr, mid + 1, rr, p * 2 + 1));
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> h;
        res = query(h + 1, MAXH, 1, MAXH, 1);
        cout << i - res << " ";
        update(h, i, 1, MAXH, 1);
    }
    cout << "\n";
}
