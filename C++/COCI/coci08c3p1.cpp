#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int x;
pii arr[5];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (size_t i = 0; i < 5; i++)
    {
        arr[i].second = i + 1;
        for (size_t j = 0; j < 4; j++)
        {
            cin >> x;
            arr[i].first += x;
        }
    }

    sort(arr, arr + 5);
    cout << arr[4].second << " " << arr[4].first << "\n";
}