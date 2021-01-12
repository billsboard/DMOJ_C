#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
int A[MAXN], B[MAXN], N, T, x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    
    while(T--){
        cin >> N;
        for (size_t i = 0; i < N; i++)
        {
            cin >> x;
            A[i] = x;
        }

        for (size_t i = 0; i < N; i++)
        {
            cin >> x;
            B[i] = x;
        }

        int mx = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                if(B[j] >= A[i]) mx = max(mx, j - i);
            }
        }

        cout << "The maximum distance is " << mx << "\n";    
    }
}