#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    if(x <= 0) cout << "S";
    else if(x >= 100) cout << "G";
    else cout << "L";
}