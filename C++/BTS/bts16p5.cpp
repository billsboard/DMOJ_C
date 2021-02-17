#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 10001, inf = 1 << 30;

struct branch{
    int x, w;
};

int arr[MAXN], wei[MAXN], chr[MAXN], N, C, K, a, b, k, cnt = 0;
bool visit[MAXN];
vector<branch> adj[MAXN];

void recurse(int p){
    visit[p] = true;

    for(const branch& i : adj[p]){
        if(visit[i.x]) continue;
        recurse(i.x);
        wei[i.x] += i.w;
        wei[p] += wei[i.x];
        chr[p] += chr[i.x];
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C >> K;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
        chr[i] = arr[i];
    }
    
    adj[0].push_back({1, inf});
    for (size_t i = 1; i < N; i++)
    {
        cin >> a >> b >> k;
        adj[a].push_back({b, k});
        adj[b].push_back({a, k});
    }

    recurse(0);
    for (size_t i = 1; i <= N; i++)
    {
        if(chr[i] >= C && wei[i] <= K) {
            cnt++;
        }
    }

    cout << cnt << "\n";
}