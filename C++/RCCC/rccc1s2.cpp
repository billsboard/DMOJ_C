#pragma GCC optimize("Ofast")
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <set>

using namespace std;
const int MAXN = 1501;
typedef long long ll;
typedef pair<ll, ll> pll;

int N, arr[MAXN];
ll cnt = 0;
unordered_map<ll, vector<pll>> mp;
set<pll> s;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = i + 1; j <= N; j++)
        {
            mp[(ll) arr[i] * arr[j]].push_back(make_pair((ll) i, (ll) j));
        }
    }


    for (auto &&v : mp)
    {
        for (size_t i = 0; i < v.second.size(); i++)
        {
            for (size_t j = i + 1; j < v.second.size(); j++)
            {
                pll a = v.second[i], b = v.second[j];
                if(a.first == b.second || a.first == b.first || a.second == b.first || a.second == b.second) continue;
                cnt += 8;
            }
        }
        
    }

    cout << cnt << "\n";
}