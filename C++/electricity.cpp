#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
const int MAXN = 1e5, inf = 1 << 30;
typedef pair<int, int> pii;

int N, T, arr[MAXN], x, y, cnt = 0, idx = 0;
pii elec[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        cnt = 0;
        idx = 0;
        for (size_t i = 0; i < N; i++)
        {
            cin >> x >> y;
            arr[i] = x;
            if(y) elec[idx++] = make_pair(x, i);
        }

        cnt += elec[0].first - arr[0];
        cnt += arr[N - 1] - elec[idx - 1].first;
        
        for (size_t i = 0; i < idx - 1; i++)
        {
            int l = elec[i].first, r = elec[i + 1].first;
            int li = elec[i].second, ri = elec[i + 1].second;
            int mn = inf;
            if(li == ri - 1) continue;

            for (size_t j = li; j < ri; j++)
            {
                mn = min((arr[j] - l) + (r - arr[j + 1]), mn);
            }
            cnt += mn;
        }
        
        cout << cnt << "\n";
    }
}