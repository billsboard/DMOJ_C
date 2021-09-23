#include <iostream>

using namespace std;
const int MAXN = 1001;

char mp[MAXN][MAXN];
bool visit[MAXN][MAXN], trap[MAXN][MAXN];
int N, M, cnt;

void dfs(int x, int y) {
    if(visit[x][y]) return;
    visit[x][y] = true;

    int a = x, b = y;
    if(mp[x][y] == 'S') {
        a++;
    }
    else if(mp[x][y] == 'N') {
        a--;
    }
    else if(mp[x][y] == 'E') {
        b++;
    }
    else {
        b--;
    }

    if(a <= 0 || b <= 0 || a > N || b > M) {
        cnt++;
        trap[x][y] = true;
    }
    else {
        dfs(a, b);
        if(trap[a][b]) {
            trap[x][y] = true;
        }
        else {
            trap[x][y] = true;
            cnt++;
        }
    }
    
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            cin >> mp[i][j];
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= M; j++)
        {
            dfs(i, j);
        }
    }

    cout << cnt << "\n";
}