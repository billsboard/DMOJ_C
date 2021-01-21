#include <iostream>
#include <queue>
#include <utility>
#include <bitset>

using namespace std;
const int MAXN = 25;
typedef pair<int, int> pii;
typedef bitset<MAXN> bs;

int N, x;
bs st;
bool visit[1 << MAXN];

int expand(int currState, int i){
    bs state (currState);
    int l = i - 1, r = i + 1;
    int lC = 0, rC = 0;
    while (l >= 0)
    {
        if(state[l] == 0) break;
        lC++;
        l--;
    }
    while (r < N){
        if(state[r] == 0) break;
        rC++;
        r++;
    }

    if(lC + rC + 1 >= 4){
        for (int j = i - 1; lC > 0; j--, lC--)
        {
            state[j] = 0;
        }
        for (int j = i + 1; rC > 0; j++, rC--)
        {
            state[j] = 0;
        }
        return (int) state.to_ulong();
    }
    else {
        state[i] = 1;
        return (int) state.to_ulong(); 
    }
}

int bfs(){
    queue<pii> q;
    q.push(make_pair((int) st.to_ulong(), 0));
    while (!q.empty())
    {
        pii v = q.front();
        q.pop();
        if(v.first == 0) return v.second;
        for (size_t i = 0; i < N; i++)
        {
            if(!(v.first & (1 << N))){
                int exp = expand(v.first, i);
                if(!visit[exp]){
                    q.push(make_pair(exp, v.second + 1));
                    visit[exp] = true;
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        st[i] = x;
    }
    cout << bfs() << "\n";
}
