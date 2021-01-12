#include <iostream>

using namespace std;

const int inf = 1 << 30;
int N, x, y, xMax = -inf, xMin = inf, yMax = -inf, yMin = inf;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        xMax = max(xMax, x);
        xMin = min(xMin, x);
        yMax = max(yMax, y);
        yMin = min(yMin, y);
    }

    cout << (yMax - yMin) * (xMax - xMin) << "\n";
}