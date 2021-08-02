#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXN = 100001;

int N, Q, a, b, c, djs[MAXN], sz[MAXN];

int root(int n){
    if(djs[n] == n) return n;
    else {
        return djs[n] = root(djs[n]);
    }
}

void uni(int a, int b){
    int x = root(a), y = root(b);
    if(x == y) return;

    else {
        djs[x] = y;
        sz[y] += sz[x];
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    for (size_t i = 0; i <= N; i++)
    {
        djs[i] = i;
        sz[i] = 1;
    }

    for (size_t i = 0; i < Q; i++)
    {
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            uni(b, c);
        }
        else {
            cin >> b;
            cout << sz[root(b)] << "\n";
        }
    }
    
}