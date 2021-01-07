#include <iostream>

using namespace std;

const int MAXN = 10000;
char arr[MAXN], ans[MAXN];
int N, cnt = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (size_t i = 0; i < N; i++)
    {
        cin >> ans[i];
    }

    for (size_t i = 0; i < N; i++)
    {
        cnt += arr[i] == ans[i];
    }
    
    cout << cnt << "\n";
}