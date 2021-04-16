#include <iostream>
#include <algorithm>

using namespace std;
const int MAXR = 1001;

int T, R, C, arr[MAXR][MAXR], row[MAXR][MAXR], col[MAXR][MAXR], cnt = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cin >> R >> C;
        cnt = 0;

        //fill(&arr[0][0], &arr[0][0] + sizeof(arr) / sizeof(arr[0][0]), 0);
        //fill(&row[0][0], &row[0][0] + sizeof(row) / sizeof(row[0][0]), 0);
        //fill(&col[0][0], &col[0][0] + sizeof(col) / sizeof(col[0][0]), 0);

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
                if(!arr[i][j]) continue;

                int idx = i;
                int u = 0, d = 0, l = 0, r = 0;
                while (idx > 0 && arr[idx][j])
                {
                    u++;
                    idx--;
                }

                idx = i;
                while (idx <= R && arr[idx][j])
                {
                    d++;
                    idx++;
                }

                idx = j;
                while (idx > 0 && arr[i][idx])
                {
                    l++;
                    idx--;
                }

                idx = j;
                while (idx <= C && arr[i][idx])
                {
                    r++;
                    idx++;
                }

                
                cnt += max(0, min(l * 2, u) / 2 - 1);
                cnt += max(0, min(r * 2, u) / 2 - 1);

                cnt += max(0, min(l * 2, d) / 2 - 1);
                cnt += max(0, min(r * 2, d) / 2 - 1);
                
                cnt += max(0, min(u * 2, l) / 2 - 1);
                cnt += max(0, min(d * 2, l) / 2 - 1);
                
                cnt += max(0, min(u * 2, r) / 2 - 1);
                cnt += max(0, min(d * 2, r) / 2 - 1);

                //cout << l << " " << r << " " << u << " " << d << "\n";
            }
            
        }
        
        



        cout << cnt << "\n";
    }
    
}
