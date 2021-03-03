#include <iostream>

using namespace std;

int B, P;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> B;
    P = 5 * B - 400;
    cout << P << "\n";
    cout << (P == 100 ? 0 : (P < 100 ? 1 : -1)) << "\n";
}