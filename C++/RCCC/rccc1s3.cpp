#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;
const int MAXN = 1001, inf = 1 << 30;

bool visit[MAXN];
int N, M, arr[MAXN], idx[MAXN], t, u, par[MAXN];
vector<int> adj[MAXN];
vector<pair<int, int>> res;
stack<pair<int, int>> stk, stk2;

int bestIdx(int p, int v){
    visit[p] = true;
    int bst;
    if(arr[p] < v) bst = inf;
    else bst = p;

    for (int x : adj[p])
    {
        if(!visit[x]){
            par[x] = p;
            bst = min(bst, bestIdx(x, v));
        }
    }
    return bst;
}

int main(){
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    for(int i = 0; i < M; i++){
        cin >> t >> u;
        adj[t].push_back(u);
        adj[u].push_back(t);
    }

    for(int i = 1; i <= N; i++){
        fill(&visit[0], &visit[0] + sizeof(visit) / sizeof(bool), false);
        fill(&par[0], &par[0] + sizeof(par) / sizeof(int), 0);
        int b = bestIdx(idx[i], i), p = arr[i];
        if(b == inf) continue;
        else if(b == idx[i]) continue;
        
        int z = b;
        while (z != idx[i] && z != 0 && par[z] != 0)
        {
            stk.push(make_pair(z, par[z]));
            z = par[z];

        };

        while (!stk.empty())
        {
            pair<int, int> p = stk.top();
            stk2.push(p);
            stk.pop();
            res.push_back(p);

            /*int v1 = arr[p.first], v2 = arr[p.second];
            swap(arr[p.first], arr[p.second]);
            idx[v1] = p.second;
            idx[v2] = p.first;*/
        }

        int v1 = arr[idx[i]], v2 = arr[b];
        swap(arr[idx[i]], arr[b]);
        idx[v2] = idx[i];
        idx[v1] = b;

        stk2.pop();
        while (!stk2.empty()){
            pair<int, int> p = stk2.top();
            stk2.pop();
            res.push_back(p);
        }
        
        
    }
    
    cout << res.size() << "\n";

    for(int i = 1; i <= N; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    for(pair<int, int> p : res){
        cout << p.first << " " << p.second << "\n";
    }
}