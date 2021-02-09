#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
const int MAXN = 101, inf = 1 << 30;

int L, N, mx = -inf, old;
string s, t, home;
unordered_map<string, vector<string>> adj;

void dfs(string p, string e, int h){
    mx = max(h, mx);
    for (string x : adj[e])
    {
        if(x == p) continue;
        dfs(e, x, h + 1);
    }
    
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> L;
    for (size_t i = 0; i < L; i++)
    {
        cin >> N;
        old = 10 * N;
        adj.clear();
        mx = -inf;
        for (size_t j = 0; j < N; j += 2)
        {
            cin >> s >> t;
            adj[s].push_back(t);
            adj[t].push_back(s);
        }
        home = t;
        dfs("", home, 1);
        cout << old - (mx - 1) * 20 << "\n";
    }
}