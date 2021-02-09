#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;
const int MAXN = 3001;
typedef long long ll;
typedef pair<int, int> pii;
ll inf = 1LL << 62;

int N, X, Q;
ll dist[MAXN], v;
bool visit[MAXN];
pii arr[MAXN];

void bfs(){
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(dist[0]), inf);
    dist[X - 1] = 0;
    int c = -1;
    ll mn = inf + 1;

    while(true){
        c = -1; mn = inf + 1;
        for (size_t i = 0; i < N; i++)
        {
            if(dist[i] < mn && !visit[i]){
                c = i;
                mn = dist[i];
            }
        }

        if(c == -1) return;
        visit[c] = true;
        pii cur = arr[c];
        for (size_t i = 0; i < N; i++)
        {
            if(i == c) continue;
            pii loc = arr[i];
            ll d = (ll) abs(loc.first - cur.first) * abs(loc.first - cur.first) + 
            (ll) abs(loc.second - cur.second) * abs(loc.second - cur.second);
            if(dist[c] + d < dist[i]) dist[i] = dist[c] + d;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    cin >> X;
    bfs();
    cin >> Q;
    sort(dist, dist + N);
    for (size_t i = 0; i < Q; i++)
    {
        cin >> v;
        cout << upper_bound(dist, dist + N, v) - dist << "\n";
    }
}