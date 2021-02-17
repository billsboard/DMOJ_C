#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, arr[3];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        
        if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]){
            cout << "R" << "\n";
            continue;
        }
        else {
            double tmp = (arr[0] * arr[0] + arr[1] * arr[1] - arr[2] * arr[2]) / ((double) (2 * arr[0] * arr[1]));
            if(abs(acos(tmp)) > (M_PI / 2)) cout << "O";
            else cout << "A";
            cout << "\n";
        }
    }
}