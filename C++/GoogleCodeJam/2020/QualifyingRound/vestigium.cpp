#include <iostream>
#include <set>

using namespace std;
const int MAXN = 101;

int N, M, T, arr[MAXN][MAXN];
set<int> row[MAXN], col[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> N;
        M = N;

        for (size_t i = 0; i < N; i++)
        {
            row[i].clear();
        }
        for (size_t i = 0; i < M; i++)
        {
            col[i].clear();
        }
        
        

        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < M; j++)
            {
                cin >> arr[i][j];
                col[j].insert(arr[i][j]);
                row[i].insert(arr[i][j]);
            }
        }

        int x = 0, y = 0, sum = 0;
        while (x < N && y < M)
        {
            sum += arr[x][y];
            x++; y++;
        }

        cout << "Case #" << t << ": " << sum;
        
        int cnt = 0;
        for (size_t i = 0; i < N; i++)
        {
            if(row[i].size() != N) cnt++;
        }

        cout << " " << cnt << " ";

        cnt = 0;
        for (size_t i = 0; i < M; i++)
        {
            if(col[i].size() != M) cnt++;
        }

        cout << cnt << "\n";
    }
    
}