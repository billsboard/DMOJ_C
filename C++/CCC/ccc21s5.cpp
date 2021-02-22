#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 150001;

struct con
{
    int l, r, z;
};

int segG[MAXN * 4], segL[MAXN * 4], N, M, l, r, z, lazy[MAXN * 4];
con arr[MAXN];

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b); 
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

void updateL(int ql, int qr, int v, int rl, int rr, int p){
    if(lazy[p] != 1){
        segL[p] = lcm(lazy[p], segL[p]);
        if(rl != rr){
            lazy[p * 2] = lcm(lazy[p * 2], lazy[p]);
            lazy[p * 2 + 1] = lcm(lazy[p * 2 + 1], lazy[p]);
        }
        lazy[p] = 1;
    }

    if(rr < ql || rl > qr) return;
    else if(ql <= rl && rr <= qr){
        segL[p] = lcm(v, segL[p]);
        if(rl != rr){
            lazy[p * 2] = lcm(lazy[p * 2], v);
            lazy[p * 2 + 1] = lcm(lazy[p * 2 + 1], v);
        }
    }
    else {
        int mid = (rl + rr) / 2;
        updateL(ql, qr, v, rl, mid, p * 2);
        updateL(ql, qr, v, mid + 1, rr, p * 2 + 1);
        segL[p] = lcm(segL[p * 2], segL[p * 2 + 1]);
    }
}

int queryL(int ql, int qr, int rl, int rr, int p){
    if(lazy[p] != 1){
        segL[p] = lcm(lazy[p], segL[p]);
        if(rl != rr){
            lazy[p * 2] = lcm(lazy[p * 2], lazy[p]);
            lazy[p * 2 + 1] = lcm(lazy[p * 2 + 1], lazy[p]);
        }
        lazy[p] = 1;
    }

    if(rr < ql || rl > qr) return 1;
    else if(ql <= rl && rr <= qr) return segL[p];
    else {
        int mid = (rl + rr) / 2;
        return lcm(
            queryL(ql, qr, rl, mid, p * 2),
            queryL(ql, qr, mid + 1, rr, p * 2 + 1)
        );
    }
}

void updateG(int i, int v, int rl, int rr, int p){
    if(rl == rr) segG[p] = v;
    else{
        int mid = (rl + rr) / 2;
        if(i <= mid) updateG(i, v, rl, mid, p * 2);
        else updateG(i, v, mid + 1, rr, p * 2 + 1);
        segG[p] = gcd(segG[p * 2], segG[p * 2 + 1]);
    }
}

int queryG(int ql, int qr, int rl, int rr, int p){
    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) return segG[p];
    else {
        int mid = (rl + rr) / 2;
        return gcd(
            queryG(ql, qr, rl, mid, p * 2),
            queryG(ql, qr, mid + 1, rr, p * 2 + 1)
        );
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    fill(&lazy[0], &lazy[0] + sizeof(lazy) / sizeof(lazy[0]), 1);
    fill(&segL[0], &segL[0] + sizeof(segL) / sizeof(segL[0]), 1);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> l >> r >> z;
        updateL(l, r, z, 1, N, 1);
        arr[i] = {l, r, z};
    }

    for (size_t i = 1; i <= N; i++)
    {
        updateG(i, queryL(i, i, 1, N, 1), 1, N, 1);
    }

    for (size_t i = 0; i < M; i++)
    {
        int res = queryG(arr[i].l, arr[i].r, 1, N, 1);
        if(res != arr[i].z){
            cout << "Impossible\n";
            return 0;
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        cout << queryG(i, i, 1, N, 1) << " ";
    }
    cout << "\n";
}