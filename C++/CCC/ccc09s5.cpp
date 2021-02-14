#include <iostream>
#include <cmath>

using namespace std;
const int MAXR = 30001, MAXC = 1001;
typedef long long ll;

ll da[MAXC][MAXR];
int N, R, C, x, y, r, b, mx = -1, cnt = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y >> r >> b;
        for (size_t j = max(1, x - r); j <= min(C, x + r); j++)
        {
            int v = sqrt((r * r) - ((x - j) * (x - j)));
            int s = max(1, y - v), e = min(R, y + v);
            da[j][s] += b;
            da[j][e + 1] -= b; 
        }
    }

    for (size_t i = 1; i <= C; i++)
    {
        long long cur = 0;
        for (size_t j = 1; j <= R; j++)
        {
            cur += da[i][j];
            if(cur == mx){
                cnt++;
            }
            else if(cur > mx){
                mx = cur;
                cnt = 1;
            }
        }
    }
    cout << mx << "\n" << cnt << "\n";
}