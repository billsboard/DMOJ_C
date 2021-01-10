#include <iostream>

using namespace std;

int N, x, y, xP, yP, xFirst, yFirst;
int A = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> xP >> yP;
    xFirst = xP; yFirst = yP;

    for (size_t i = 1; i < N; i++)
    {
        cin >> x >> y;
        A += xP * y - yP * x;
        xP = x; yP = y;
    }

    A += x * yFirst - y * xFirst;

    cout << (abs(A) + 1) / 2 << "\n";
}