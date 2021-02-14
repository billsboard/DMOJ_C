#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN = 5002;

bool visit[MAXN], stk[MAXN], v2[MAXN], flag = false;
int T, N, idx = 1, P;
string s, t;
unordered_map<string, int> mp;
vector<int> adj[MAXN], adj2[MAXN];

void recurse(int p){
    if(visit[p]) return;
    visit[p] = true;

    for(int i : adj[p]){
        if(stk[i]){
            flag = true;
            return;
        }
        stk[i] = 1;
        recurse(i);
        stk[i] = 0;
    }
}

void findAll(int p){
    if(v2[p]) return;
    v2[p] = true;

    fill(&visit[0], &visit[0] + sizeof(visit) / sizeof(visit[0]), false);
    fill(&stk[0], &stk[0] + sizeof(stk) / sizeof(stk[0]), false);
    stk[p] = true;
    if(flag) return;

    recurse(p);

    if(flag){
        return;
    }

    else {
        for(int i : adj2[p]){
            findAll(i);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> N;
        flag = false;

        fill(&visit[0], &visit[0] + sizeof(visit) / sizeof(visit[0]), false);
        fill(&stk[0], &stk[0] + sizeof(stk) / sizeof(stk[0]), false);
        fill(&v2[0], &v2[0] + sizeof(v2) / sizeof(v2[0]), false);
        mp.erase(mp.begin(), mp.end());

        for (size_t j = 0; j < MAXN; j++)
        {
            adj[j].erase(adj[j].begin(), adj[j].end());
            adj2[j].erase(adj2[j].begin(), adj2[j].end());
        }
        
        for (size_t j = 0; j < N; j++)
        {
            cin >> s;
            if(mp.find(s) == mp.end()){
                mp[s] = idx;
                idx++;
            }
            cin >> P;
            for (size_t k = 0; k < P; k++)
            {
                cin >> t;
                if(mp.find(t) == mp.end()){
                    mp[t] = idx;
                    idx++;
                }
                adj[mp[t]].push_back(mp[s]);
                adj2[mp[s]].push_back(mp[t]);
                adj2[mp[t]].push_back(mp[s]);
            } 

        }

        findAll(mp["Jim-Bob"]);

        if(flag){
            cout << "Redneck\n";
        }
        else cout << "Not a redneck\n";
    }
}