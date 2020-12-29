#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[100];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int l = (N - 1) >> 1, r = l + 1;
    while (l >= 0)
    {
        if(l >= 0) cout << arr[l] << " ";
        if(r < N) cout << arr[r] << " ";
        l--; r++;
    }

    cout << endl;
}   