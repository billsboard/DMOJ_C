#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
const int MAXN = 100001;

int N, M, K, x, y, djs[MAXN], cnt = 0;
char map[MAXN];
bool visit[MAXN];
string s;

int root(int i){
    if(djs[i] == i) return i;
    return djs[i] = root(djs[i]);
}

void uni(int a, int b){
    int aR = root(a), bR = root(b);
    if(aR == bR) return;
    else djs[aR] = bR;
}

bool connect(int a, int b){
    return root(a) == root(b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    cin >> s;

    for (size_t i = 0; i < MAXN; i++)
    {
        djs[i] = i;
    }

    for (size_t i = 1; i <= N; i++)
    {
        map[i] = s[i - 1];
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y;
        if(map[x] == map[y]){
            uni(x, y);
        }
    }

    for (size_t i = 0; i < K; i++)
    {
        cin >> x >> y;
        cnt += connect(x, y);
    }
    
    cout << cnt << "\n";
}