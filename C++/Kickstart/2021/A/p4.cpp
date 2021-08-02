#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
const int MAXN = 5, inf = 1 << 30;

int T, R, C, arr[MAXN][MAXN], tm[MAXN][MAXN], rc[MAXN], cc[MAXN], mrc[MAXN], mcc[MAXN], mn, N;
set<int> row[MAXN], col[MAXN];

int countRow(int r, int grid[MAXN][MAXN]){
    int cnt = 0;
    for (size_t i = 1; i <= C; i++)
    {
        if(grid[r][i] == -1) cnt++;
    }
    return cnt;
}

int chkRow(int r, int grid[MAXN][MAXN]){
    int chk = grid[r][1];
    for (size_t i = 2; i <= C; i++)
    {
        if(grid[r][i] != -1) chk ^= grid[r][i];
    }
    return chk;
}

int countCol(int c, int grid[MAXN][MAXN]){
    int cnt = 0;
    for (size_t i = 1; i <= R; i++)
    {
        if(grid[i][c] == -1) cnt++;
    }
    return cnt;
}

int chkCol(int c, int grid[MAXN][MAXN]){
    int chk = grid[1][c];
    for (size_t i = 2; i <= R; i++)
    {
        if(grid[i][c] != -1) chk ^= grid[i][c];
    }
    return chk;
}


void recurse(int tme, int grid[MAXN][MAXN]){
    if(tme > mn) return;

    //cout << countRow(1, grid) + countRow(2, grid) + countRow(3, grid) + countRow(4, grid) << "in" << endl;


    bool found = false;

    for (size_t i = 1; i <= R; i++)
    {
        int rrrr = countRow(i, grid);
        for (size_t j = 1; j <= C; j++)
        {
            if(grid[i][j] != -1) continue;

            int wtf = countCol(j, grid);
            if(rrrr == 1){
                grid[i][j] = 2;
                continue;
            }
            else if(wtf == 1){
                grid[i][j] = 2;
                continue;
            }
        }
    }
    

    for (size_t i = 1; i <= R; i++)
    {
        for (size_t j = 1; j <= C; j++)
        {
            if(grid[i][j] != -1) continue;

            found = true;
            int newArr[MAXN][MAXN];
            for (int x= 1 ; x <= R; x++){
                for (size_t y = 1; y <= C; y++)
                {
                    newArr[x][y] = grid[x][y];
                }
            }
            newArr[i][j] = 2;
            recurse(tme + tm[i][j], newArr);
        }
    }

    if(found == false){
        mn = min(mn, tme);
    }
    
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cin >> R;
        C = R;
        mn = inf;

        for (size_t i = 1; i <= R; i++)
        {
            for (size_t j = 1; j <= C; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (size_t i = 1; i <= R; i++)
        {
            for (size_t j = 1; j <= C; j++)
            {
                cin >> tm[i][j];
            }
        }

        for (size_t i = 1; i <= R; i++)
        {
            mrc[i] = arr[i][1];
            for (size_t j = 2; j <= C; j++)
            {
                mrc[i] ^= arr[i][j];
            }
        }

        for (size_t i = 1; i <= R; i++)
        {
            mcc[i] = arr[1][i];
            for (size_t j = 2; j <= C; j++)
            {
                mcc[i] ^= arr[j][i];
            }
        }

        for (size_t i = 1; i <= R; i++)
        {
            cin >> rc[i];
        }

        for (size_t i = 1; i <= C; i++)
        {
            cin >> cc[i];
        }

        recurse(0, arr);
        cout << mn << "\n";
    }
    
}
