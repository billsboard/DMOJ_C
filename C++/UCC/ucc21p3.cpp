#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 1e7 + 2;

ll N, R, x, y, l, r, diff[MAXN], cnt = 0, mv = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> x >> y >> R;
    
    for (size_t i = 0; i < R; i++)
    {
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    for (size_t i = 1; i <= N; i++)
    {
        mv += diff[i];
        if(x <= i && i <= y) cnt += mv;
    }
    
    cout << cnt << "\n";
}