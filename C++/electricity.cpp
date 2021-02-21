#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;
const int MAXN = 1e5, inf = 1 << 30;
typedef pair<int, int> pii;

vector<pii> elec;
int N, T, arr[MAXN], x, y, cnt = 0;
unordered_map<int, int> idx;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        elec.clear();
        cnt = 0;
        for (size_t i = 0; i < N; i++)
        {
            cin >> x >> y;
            arr[i] = x;
            if(y) elec.push_back(make_pair(x, i));
            idx[x] = i;
        }

        cnt += elec[0].first - arr[0];
        cnt += arr[N - 1] - elec[elec.size() - 1].first;
        
        for (size_t i = 0; i < elec.size() - 1; i++)
        {
            int l = elec[i].first, r = elec[i + 1].first;
            int li = elec[i].second, ri = elec[i].second;
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