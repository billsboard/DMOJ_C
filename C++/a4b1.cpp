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
    for (size_t i = 0; i < N; i++)
    {
        cout << arr[i] << "\n";
    }
}