#include <iostream>

using namespace std;
const int MAXN = 100001;

int psa[MAXN], W, N, cnt = 0;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> W >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> psa[i];
        psa[i] += psa[i - 1];
        if(psa[i] - psa[max(0, i - 4)] > W) break;
        cnt++;
    }

    cout << cnt << "\n";
}