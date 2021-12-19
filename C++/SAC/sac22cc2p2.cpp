#include <iostream>

using namespace std;

const int MAXN = 501;

int C[MAXN][MAXN], cnt, N, Q, t, x, y, x2, y2;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> t;
        if(t == 1) {
            cin >> x >> y;
            C[x][y]++;
        }
        else {
            cin >> x >> y >> x2 >> y2;
            for (size_t i = x; i <= x2; i++)
            {
                for (size_t j = y; j <= y2; j++)
                {
                    cnt += C[i][j];
                }
            }
        }
    }

    cout << cnt << "\n";
}