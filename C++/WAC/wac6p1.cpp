#include <iostream>

using namespace std;

int N;
double P, C;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> P >> C;
        cout << 100 * P / (C + 100) << "\n";
    }
}