#include <iostream>
#include <cstdio>

using namespace std;
const int MAXN = 100001;

int psa[3][MAXN];
// 0 = hoof, 1 = paper, 2 = sci 
int N, mx = 0;
char c;

int query(int i, int l, int r){
    return psa[i][r] - psa[i][l - 1];
}

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        psa[0][i] = psa[0][i - 1];
        psa[1][i] = psa[1][i - 1];
        psa[2][i] = psa[2][i - 1];

        cin >> c;
        if(c == 'H') psa[0][i]++;
        else if(c == 'P') psa[1][i]++;
        else if(c == 'S') psa[2][i]++;
    }

    for (size_t i = 1; i < N; i++)
    {
        int mxl = 0, mxr = 0;
        for (size_t j = 0; j < 3; j++)
        {
            mxl = max(mxl, query(j, 1, i));
            mxr = max(mxr, query(j, i + 1, N));            
        }
        mx = max(mx, mxl + mxr);
    }

    cout << mx << "\n";
}