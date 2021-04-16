#include <iostream>
#include <utility>
#include <set>

using namespace std;
const int MAXC = 301;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int T, R, C, arr[MAXC][MAXC], tmp[MAXC][MAXC];
ll cnt = 0;
set<piiii> ldiff;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cnt = 0;
        cin >> R >> C;
        for (size_t i = 1; i <= R; i++)
        {
            for (size_t j = 1; j <= C; j++)
            {
                cin >> arr[i][j];
                tmp[i][j] = arr[i][j];
            }
        }

        for (size_t i = 1; i <= R; i++) {
            for (size_t j = 1; j <= C; j++) {
                if(i + 1 <= R && abs(arr[i][j] - arr[i + 1][j]) > 1){
                    ldiff.insert(make_pair(make_pair(i, j), make_pair(i + 1, j)));
                }
                if(j + 1 <= C && abs(arr[i][j] - arr[i][j + 1]) > 1){
                    ldiff.insert(make_pair(make_pair(i, j), make_pair(i, j + 1)));
                }
            }
        }
        
        while (!ldiff.empty())
        {
            piiii p = *ldiff.begin(); 
            ldiff.erase(p);

            pii a = p.first, b = p.second;
            if(abs(arr[a.first][a.second] - arr[b.first][b.second]) <= 1) continue;

            if(arr[a.first][a.second] > arr[b.first][b.second]){
                arr[b.first][b.second] = arr[a.first][a.second] - 1;

                if(b.first + 1 <= R){
                    if(abs(arr[b.first][b.second] - arr[b.first + 1][b.second]) > 1){
                        ldiff.insert(make_pair(make_pair(b.first, b.second), make_pair(b.first + 1, b.second)));
                    }
                }

                if(b.second + 1 <= C){
                    if(abs(arr[b.first][b.second] - arr[b.first][b.second + 1]) > 1){
                        ldiff.insert(make_pair(make_pair(b.first, b.second), make_pair(b.first, b.second + 1)));
                    }
                }

                if (b.first - 1 > 0){
                    if(abs(arr[b.first][b.second] - arr[b.first - 1][b.second]) > 1){
                        ldiff.insert(make_pair(make_pair(b.first, b.second), make_pair(b.first - 1, b.second)));
                    }
                }

                if(b.second - 1 > 0){
                    if(abs(arr[b.first][b.second] - arr[b.first][b.second - 1]) > 1){
                        ldiff.insert(make_pair(make_pair(b.first, b.second), make_pair(b.first, b.second - 1)));
                    }
                }
            }
            else {
                arr[a.first][a.second] = arr[b.first][b.second] - 1;

                if(a.first + 1 <= R){
                    if(abs(arr[a.first][a.second] - arr[a.first + 1][a.second]) > 1){
                        ldiff.insert(make_pair(make_pair(a.first, a.second), make_pair(a.first + 1, a.second)));
                    }
                }

                if(a.second + 1 <= C){
                    if(abs(arr[a.first][a.second] - arr[a.first][a.second + 1]) > 1){
                        ldiff.insert(make_pair(make_pair(a.first, a.second), make_pair(a.first, a.second + 1)));
                    }
                }

                if (a.first - 1 > 0){
                    if(abs(arr[a.first][a.second] - arr[a.first - 1][a.second]) > 1){
                        ldiff.insert(make_pair(make_pair(a.first, a.second), make_pair(a.first - 1, a.second)));
                    }
                }

                if(a.second - 1 > 0){
                    if(abs(arr[a.first][a.second] - arr[a.first][a.second - 1]) > 1){
                        ldiff.insert(make_pair(make_pair(a.first, a.second), make_pair(a.first, a.second - 1)));
                    }
                }
            }

        }

        for (size_t i = 1; i <= R; i++)
        {
            for (size_t j = 1; j <= C; j++)
            {
                //cout << arr[i][j] << " ";
                cnt += arr[i][j] - tmp[i][j];
            }
            //cout << "\n";
            
        }
        
        
        cout << cnt << "\n";
    }
    
}