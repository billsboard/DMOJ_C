#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 100001;

int N, Q, freq[MAXN], fSeg[MAXN * 4], l, r, x, v;
ll arr[MAXN], seg[MAXN * 4];
char c;

void buildSum(int rl, int rr, int p){
    if(rl == rr) seg[p] = arr[rl];
    else{
        int mid = (rl + rr) / 2;
        buildSum(rl, mid, p * 2);
        buildSum(mid + 1, rr, p * 2 + 1);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void buildFreq(int rl, int rr, int p){
    if(rl == rr) fSeg[p] = freq[rl];
    else{
        int mid = (rl + rr) / 2;
        buildFreq(rl, mid, p * 2);
        buildFreq(mid + 1, rr, p * 2 + 1);
        fSeg[p] = fSeg[p * 2] + fSeg[p * 2 + 1];
    }
}

void updateSum(int i, int v, int rl, int rr, int p){
    if(rl == rr) seg[p] = v;
    else{
        int mid = (rl + rr) / 2;
        if(i <= mid) updateSum(i, v, rl, mid, p * 2);
        else updateSum(i, v, mid + 1, rr, p * 2 + 1);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

void updateFreq(int i, int v, int rl, int rr, int p){
    if(rl == rr) fSeg[p] += v;
    else{
        int mid = (rl + rr) / 2;
        if(i <= mid) updateFreq(i, v, rl, mid, p * 2);
        else updateFreq(i, v, mid + 1, rr, p * 2 + 1);
        fSeg[p] = fSeg[p * 2] + fSeg[p * 2 + 1];
    }
}

ll querySum(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) return seg[p];
    else{
        int mid = (rl + rr) / 2;
        return querySum(ql, qr, rl, mid, p * 2) + querySum(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

int queryFreq(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) return fSeg[p];
    else{
        int mid = (rl + rr) / 2;
        return queryFreq(ql, qr, rl, mid, p * 2) + queryFreq(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> x;
        arr[i] = x;
        freq[x]++;
    }

    buildSum(1, N, 1);
    buildFreq(1, MAXN - 1, 1);

    for (size_t i = 0; i < Q; i++)
    {
        cin >> c;
        switch (c)
        {
        case 'C':
            cin >> x >> v;
            updateFreq(arr[x], -1, 1, MAXN - 1, 1);
            arr[x] = v;
            updateSum(x, v, 1, N, 1);
            updateFreq(v, 1, 1, MAXN - 1, 1);
            break;
        case 'S':
            cin >> l >> r;
            cout << querySum(l, r, 1, N, 1) << "\n";
            break;
        case 'Q':
            cin >> v;
            cout << queryFreq(1, v, 1, MAXN - 1, 1) << "\n";
            break;
        }
    }
}