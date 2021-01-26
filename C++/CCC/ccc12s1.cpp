#include <iostream>

using namespace std;

int N;

int main(){
    cin >> N;
    cout << (N - 1) * (N - 2) * (N - 3) / 6 << "\n";
}