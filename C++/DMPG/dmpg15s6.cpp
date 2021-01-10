#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<string, double> psi;

const double ep = 1e-9;

unordered_map<string, vector<psi>> adj;
unordered_map<string, double> cnt;

int N, M;
double d;
string S, T;
bool infAppl;

void bfs(){
    queue<string> q;
    q.push("APPLES");
    while (!q.empty())
    {
        string v = q.front();
        q.pop();

        for(psi p : adj[v]){
            if(p.first == "APPLES"){
                if(cnt[v] * p.second > 1 && abs(cnt[v] * p.second - 1.0) > ep){
                    infAppl = 1;
                    return;
                }
            }
            else if(cnt[v] * p.second > cnt[p.first] && abs(cnt[v] * p.second - cnt[p.first]) > ep){
                cnt[p.first] = cnt[v] * p.second;
                q.push(p.first);
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> S;
        cnt[S] = 0;
    }
    
    for (size_t i = 0; i < M; i++)
    {
        cin >> S >> T >> d;
        adj[S].push_back(make_pair(T, d));
    }

    cnt["APPLES"] = 1;
    bfs();
    cout << (infAppl ? "YA" : "NAW") << "\n";
}