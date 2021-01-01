#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 102;

char grid[2 * MAXN][MAXN], c;
int N, X = 0, Y = 101, maxY = 101, minY = 101;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.sync_with_stdio(0);
    cout.tie(0);

    cin >> N;

    fill(&grid[0][0], &grid[0][0] + sizeof(grid) / sizeof(char), '.');

    for (size_t i = 0; i < N; i++)
    {
        cin >> c;
        switch (c)
        {
        case '+':
            grid[Y][X] = '/';
            Y++;
            maxY = max(Y, maxY);
            break;
        case '-':
            Y--;
            grid[Y][X] = '\\';
            minY = min(Y, minY);
            break;
        default:
            grid[Y][X] = '_';
            maxY += maxY == Y;
            break;
        }
        X++;
    }

    maxY += maxY == minY;
    for (size_t i = maxY - 1; i >= minY; i--)
    {
        for (size_t j = 0; j < X; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}