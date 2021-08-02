#include <iostream>
#include <unordered_map>
#include <utility>
#include <set>

using namespace std;
const int MAXN = 1500;
typedef long long ll;
typedef pair<ll, ll> pll;

int N, arr[MAXN], cnt = 0;
set<pll> s;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if(i == j) continue;
            ll res = (ll) arr[i] * arr[j];

            for (size_t k = 0; k < N; k++)
            {
                if(k == i || k == j) continue;
                for (size_t l = 0; l < N; l++)
                {
                    if(l == k || l == i || l == j) continue;
                    ll res2 = (ll) arr[k] * arr[l];
                    if(res == res2){
                        s.insert(make_pair(i << 32 | j, k << 32 | l));
                    }
                }
                
            }
            
        }
        
    }

    cout << s.size() << "\n";
}
