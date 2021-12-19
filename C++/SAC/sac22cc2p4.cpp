#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;
const int MAXN = 1001, inf = 1 << 30;

struct pt {
    int x, y, d;
};

struct compareTo {
    bool operator() (const pt& a, const pt& b) {
        return a.d > b.d;
    }
};

int dirs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, N, M, dist[MAXN][MAXN];
bool visit[MAXN][MAXN];
char arr[MAXN][MAXN];


void bfs() {
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(dist[0][0]), inf);
    dist[1][1] = 0;
    if(arr[1][1] == 'C') dist[1][1] = 1;
    priority_queue<pt, vector<pt>, compareTo> q;
    q.push(pt{1, 1, dist[1][1]});
    while (!q.empty())
    {
        pt v = q.top();
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            pt p = {v.x + dirs[i][0], v.y + dirs[i][1], 0};
            if(p.x < 1 || p.y < 1 || p.x > N || p.y > M) continue;

            int d = 0;
            if(arr[p.x][p.y] == 'C') d = 1;

            if(dist[p.x][p.y] > v.d + d) {
                dist[p.x][p.y] = v.d + d;
                q.push(pt{p.x, p.y, v.d + d});
            }
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
            cin >> arr[i][j];
        }
    }

    bfs();

    cout << dist[N][M] << "\n";
}