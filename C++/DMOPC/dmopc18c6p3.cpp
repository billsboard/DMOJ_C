#include <iostream>


using namespace std;
const int MAXN = 200001;

int djs[MAXN], sz[MAXN], M, N, u, v, cnt = 0;
bool pres[MAXN];

int root(int p) {
    if(djs[p] == p) return p;
    return djs[p] = root(djs[p]);
}

void uni(int a, int b) {
    int x = root(a), y = root(b);
    if(x == y) return;

    if(sz[x] > sz[y]) {
        swap(y, x);
    }

    djs[x] = y;
    sz[y] += sz[x];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i <= N; i++)
    {
        djs[i] = i;
        sz[i] = 1;
    }
    

    for (size_t i = 0; i < M; i++)
    {
        cin >> u >> v;
        uni(u, v);
    }

    int r;
    for (size_t i = 1; i <= N; i++)
    {
        r = root(i);
        if(pres[r]) continue;
        
        pres[r] = true;
        cnt++;
    }

    if(M == N - cnt || M == N - cnt + 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    cout << "\n";
}