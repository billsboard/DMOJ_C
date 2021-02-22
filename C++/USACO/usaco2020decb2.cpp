#include <iostream>
#include <bitset>

using namespace std;
const int MAXN = 101, MAXV = 1001;
typedef bitset<MAXV> bs;

int psa[MAXN], arr[MAXN], N, cnt = 0;
bs seg[MAXN * 4];

void build(int rl, int rr, int p){
    if(rl == rr){
        seg[p] = bs();
        seg[p][arr[rl]] = 1;
    }
    else {
        int mid = (rl + rr) / 2;
        build(rl, mid, p * 2);
        build(mid + 1, rr, p * 2 + 1);
        seg[p] = bs();
        seg[p] |= seg[p * 2];
        seg[p] |= seg[p * 2 + 1];
    }
}

bs query(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return bs();
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) / 2;
        bs res = bs();
        res |= query(ql, qr, rl, mid, p * 2);
        res |= query(ql, qr, mid + 1, rr, p * 2 + 1);
        return res;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        psa[i] = psa[i - 1] + arr[i];
    }
    
    build(1, N, 1);


    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = i + 1; j <= N; j++)
        {
            int num = j - i + 1, s = psa[j] - psa[i - 1];
            if(s > 1000 * num || s % num) continue;

            bs res = query(i, j, 1, N, 1);
            if(res[s / num]) cnt++;
        }
    }
    cout << cnt + N << "\n";
}