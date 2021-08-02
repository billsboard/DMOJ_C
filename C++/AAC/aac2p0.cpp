#include <iostream>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << (N + N - 2) / 2 << "\n";
}