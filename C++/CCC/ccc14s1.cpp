#include <iostream>

using namespace std;
const int MAXN = 100;
bool arr[MAXN + 1];
int N, K, r; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < K; i++)
    {
        int cnt = 0;
        cin >> r;
        for (size_t j = 1; j <= N; j++)
        {
            cnt += arr[j] ? 0 : 1;
            if(cnt == r){
                cnt = 0;
                arr[j] = 1;
                continue;
            }
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        if(!arr[i]) cout << i << "\n";
    }
    
    
}