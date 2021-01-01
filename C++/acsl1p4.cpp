#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int MAXN = 21;

vector<int> adj[MAXN];
bitset<MAXN> res;
int N, K, a, b, sA, sB;

void dfs(int v, vector<int> stk, bitset<MAXN> bs){
    for(int x : adj[v]){
        bitset<MAXN> bsCpy;
        for (size_t i = 0; i < MAXN; i++)
        {
            bsCpy[i] = bs[i];
        }
        vector<int> stkCpy = stk;

        if(bsCpy[x]){
            while (stkCpy.back() != x && stkCpy.size() > 0)
            {   
                res[stkCpy.back()] = 1;
                stkCpy.pop_back();
            }
            res[x] = 1;
        }
        else{
            bsCpy[x] = 1;
            stkCpy.push_back(x);
            dfs(x, stkCpy, bsCpy);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (size_t i = 0; i < K; i++)
    {
        cin >> a >> b >> sA >> sB;
        if(sA > sB) adj[a].push_back(b);
        else adj[b].push_back(a);
    }

    for (size_t i = 1; i <= N; i++)
    {
        vector<int> stk;
        bitset<MAXN> bs;
        stk.push_back(i);
        bs[i] = 1;
        dfs(i, stk, bs);
    }

    cout << res.count() << "\n";
}