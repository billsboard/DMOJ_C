#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1000003, inf = 1 << 30;

int arr[MAXN], sorted[MAXN], seg[MAXN * 4], N;

void update(int i, int v, int rl, int rr, int p){
    if(rl == rr) seg[p] = v;
    else{
        int mid = (rl + rr) / 2;
        if(i <= mid) update(i, v, rl, mid, p * 2);
        else update(i, v, mid + 1, rr, p * 2 + 1);
        seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
    }
}

int query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return -inf;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) / 2;
        return max(
            query(ql, qr, rl, mid, p * 2),
            query(ql, qr, mid + 1, rr, p * 2 + 1)
        );
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }

    sort(sorted + 1, sorted + 1 + N);
    for (size_t i = 1; i <= N; i++)
    {
        arr[i] = lower_bound(sorted + 1, sorted + 1 + N, arr[i]) - sorted;
    }

    fill(&seg[0], &seg[0] + sizeof(seg) / sizeof(seg[0]), -inf);

    update(arr[1], 1, 1, N, 1);
    for (size_t i = 2; i <= N; i++)
    {
        int res = query(1, arr[i] - 1, 1, N, 1);
        int cur = query(arr[i], arr[i], 1, N, 1);

        int mx = max(1, max(res + 1, cur));
        update(arr[i], mx, 1, N, 1);
    }
    
    cout << query(1, N, 1, N, 1) << "\n";
}