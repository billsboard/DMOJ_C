#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXS = 27;

vector<int> adj[MAXS];
vector<char> element[MAXS];
bool visit[MAXS], pres[MAXS];
int N;
string x, y;
set<char> res;

void bfs(int i){
    res.clear();
    fill(&visit[0], &visit[0] + sizeof(visit) / sizeof(bool), false);
    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if(visit[v]) continue;
        visit[v] = true;

        for (char c : element[v])
        {
            res.insert(c);        
        }
        for(int e : adj[v]){
            q.push(e);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y >> y;
        if(y[0] <= 'Z'){
            adj[x[0] - 'A'].push_back(y[0] - 'A');
            pres[y[0] - 'A'] = true;
        }
        else{
            element[x[0] - 'A'].push_back(y[0]);
        }
        pres[x[0] - 'A'] = true;      
    }

    for (size_t i = 0; i < MAXS; i++)
    {
        if(!pres[i]) continue;
        cout << (char) (i + 'A') << " = {";
        bfs(i);
        if(res.empty()) cout << "}";
        else {
            string sR = "";
            for (char c : res)
            {
                sR += c;
                sR += ',';
            }
            sR[sR.length() - 1] = '}';
            cout << sR;
        }
        cout << "\n";
    }
}
