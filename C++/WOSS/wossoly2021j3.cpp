#include <iostream>

using namespace std;
typedef long long ll;

int mv[] = {1, 5, 10, 50, 100, 500, 1000};
ll D, cnt, res[7];

int main() {
    cin >> D;
    int i = 6;

    while (i >= 0)
    {
        res[i] = D / mv[i];
        D -= (D / mv[i]) * mv[i];
        i--;
    }

    for (size_t i = 0; i < 7; i++)
    {
        cout << res[i] << " ";
    }
}