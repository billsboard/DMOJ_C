#include <iostream>

using namespace std;

const int MAXN = 102, inf = 1 << 30;

int T[MAXN], F[MAXN], N, M, H, L, D, mn, tm, cnt, pr; 

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        mn = inf;
        cin >> D >> M >> H >> L;
        for (size_t i = 1; i <= M; i++)
        {
            cin >> T[i] >> F[i];
        }
        T[0] = 0; F[0] = 0;
        T[M + 1] = D; F[M + 1] = 0;

        if(M == 0) {
            cout << 0 << "\n";
            continue;
        }

        for (size_t i = 0; i <= M; i++)
        {
            tm = 0; cnt = 0; pr = 0;
            for (size_t j = 0; j <= M + 1; j++)
            {
                if(i == j) continue;

                if(H <= cnt && cnt < L) {
                    tm += T[j] - pr;
                }
                if(cnt >= L) {
                    break;
                }

                cnt += F[j];
                if(cnt < 0) cnt = 0;
                pr = T[j];
            }
            mn = min(mn, tm);
        }
        cout << mn << "\n";
    }
}