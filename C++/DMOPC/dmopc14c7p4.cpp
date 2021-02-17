#include <iostream>

using namespace std;
typedef long long ll;

int N;

int main(){
    cin >> N;
    int st = 1, diff = 1;
    while (st + diff - 1 < N)
    {
        st += diff;
        diff++;
    }

    cout << ((ll) (st + st + diff - 1)) * diff / 2 << "\n"; 
}