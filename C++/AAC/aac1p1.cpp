#include <iostream>

using namespace std;

int S, R;

int main(){
    cin >> S >> R;
    if(S * S > 3.14 * R * R) cout << "SQUARE";
    else cout << "CIRCLE";
    cout << "\n";
}