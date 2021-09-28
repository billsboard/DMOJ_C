#include <iostream>
#include <utility>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int MAXH = 1001, inf = 1 << 30;

pii mp[MAXH][MAXH], st, en, none = {-1, -1};
int dist[MAXH][MAXH], N, H, V, x, y, a1, a2, b1, b2, dirs[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

struct val {
    int x, y, d;
};

struct compareTo
{
    bool operator()(const val& a, const val& b) {
        return a.d > b.d;
    }
};


void bfs() {
    priority_queue<val, vector<val>, compareTo> q;
    fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(dist[0][0]), inf);
    dist[st.first][st.second] = 0;
    q.push(val{st.first, st.second, 0});
    while (!q.empty())
    {
        val v = q.top();
        q.pop();

        if(mp[v.x][v.y] != none) {
            pii res = mp[v.x][v.y];
            if(dist[res.first][res.second] > dist[v.x][v.y]) {
                dist[res.first][res.second] = dist[v.x][v.y];
                q.push(val{res.first, res.second, dist[v.x][v.y]});
            }
        }

        for (size_t i = 0; i < 4; i++)
        {
            int nx = v.x + dirs[i][0], ny = v.y + dirs[i][1];
            if(nx < 0 || ny < 0 || nx > H || ny > V) continue;
            
            if(dist[nx][ny] > dist[v.x][v.y] + 1) {
               dist[nx][ny] = dist[v.x][v.y] + 1;
               q.push(val{nx, ny, dist[v.x][v.y] + 1});
            }
        }
    }
    
}

int main() {
    for (size_t i = 0; i < 10; i++)
    {
        cin >> H >> V >> x >> y;
        st = make_pair(x, y);
        cin >> x >> y;
        en = make_pair(x, y);
        cin >> N;
        
        for (size_t j = 0; j <= H; j++)
        {
            for (size_t k = 0; k <= V; k++)
            {
                mp[j][k] = make_pair(-1, -1);
            }
        }

        for (size_t j = 0; j < N; j++)
        {
            cin >> a1 >> b1 >> a2 >> b2;
            mp[a1][b1] = make_pair(a2, b2); 
            mp[a2][b2] = make_pair(a1, b1); 
        }

        bfs();
        cout << dist[en.first][en.second] << "\n";
    }
    
}