#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 101, inf = 1 << 30;

int arr[MAXN], T, N, cst = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cin >> N;
        cst = 0;
        
        for (size_t i = 1; i <= N; i++)
        {
            cin >> arr[i];
        }

        for (size_t i = 1; i < N; i++)
        {
            int mn = inf, idx = -1;
            for (size_t j = i; j <= N; j++)
            {
                if(arr[j] < mn){
                    idx = j;
                    mn = arr[j];
                }
            }

            cst += idx - i + 1;
            reverse(arr + i, arr + idx + 1);
        }
        cout << cst;
        cout << "\n";
    }   
}