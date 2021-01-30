#include <iostream>
#include <cmath>

using namespace std;
const int MAXN = 200001, SQRTN = 449, MAXQ = 200001;

int N, Q, arr[MAXN], x, l, r, v, fac[SQRTN][MAXQ];
int blkSize;

void build(){
    for (size_t i = 0; i < N; i++)
    {
        int blk = i / blkSize, sq = sqrt(arr[i]);
        for (size_t j = 1; j <= sq; j++)
        {
            if(arr[i] % j == 0){
                fac[blk][j]++;
                if(arr[i] / j != j)
                    fac[blk][arr[i] / j]++;
            }
        }
    }
}

void update(int i, int v){
    int blk = i / blkSize;
    int sq = sqrt(arr[i]);
    for (size_t j = 1; j <= sq; j++)
    {
        if(arr[i] % j == 0){
            fac[blk][j]--;
            if(arr[i] / j != j)
                fac[blk][arr[i] / j]--;
        }
    }

    arr[i] = v;
    sq = sqrt(v);
    for (size_t j = 1; j <= sq; j++)
    {
        if(v % j == 0){
            fac[blk][j]++;
            if(v / j != j)
                fac[blk][v / j]++;
        }
    }
}

int query(int l, int r, int q){
    int lBlk = l / blkSize, rBlk = r / blkSize;
    int lEnd = lBlk * blkSize + blkSize - 1, idx = l, blk, cnt = 0;

    if(lBlk == rBlk){
        for (size_t i = l; i <= r; i++)
        {
            cnt += (arr[i] % q == 0);
        }
        return cnt;
    }

    while (idx <= lEnd) {
        cnt += (arr[idx] % q == 0);
        idx++;
    }

    blk = lBlk + 1;
    while (blk < rBlk)
    {
        cnt += fac[blk][q];
        blk++;
    }

    idx = rBlk * blkSize;
    while (idx <= r)
    {
        cnt += (arr[idx] % q == 0);
        idx++;
    }
    return cnt;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    blkSize = sqrt(N);

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    build();

    for (size_t i = 0; i < Q; i++)
    {
        cin >> x;
        if(x == 1){
            cin >> l >> r >> v;
            cout << query(l - 1, r - 1, v) << "\n";
        }
        else{
            cin >> l >> v;
            update(l - 1, v);
        }
    }
}