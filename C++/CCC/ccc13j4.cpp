#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100;

int N, C, cnt = 0, arr[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);
    for(int i = 0; i < N; i++){
        if(arr[i] > C) break;
        C -= arr[i];
        cnt++;
    }

    cout << cnt << "\n";
}