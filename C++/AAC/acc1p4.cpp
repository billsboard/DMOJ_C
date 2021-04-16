#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;
const int MAXN = 1e6 + 1;
const int BLK = 1000;

int N, Q, arr[MAXN], l, r, v, s;
vector<int> mp[100001];

bool contains(int l, int r, int v){
    //if(mp.find(v) == mp.end()) return 0;

    // This is BS
    int lb = lower_bound(mp[v].begin(), mp[v].end(), l) - mp[v].begin();
    if(lb == mp[v].size()) return 0;
    return mp[v][lb] <= r && mp[v][lb] >= l;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    
    for (int i = 0; i < Q; i++)
    {
        cin >> l >> r >> v;
        s = sqrt(v);
        if(s * s == v) s--;
        if(l == r){
            cout << "NO\n";
            continue;
        }

        for(int j = 1; j <= s; j++){
            if(v % j) continue;
            if(contains(l, r, j) && contains(l, r, v / j)){
                cout << "YES";
                goto cont;
            }
        }

        cout << "NO";
    
        cont:;
        cout << "\n";
    }
}