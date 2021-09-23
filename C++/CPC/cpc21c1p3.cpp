#include <iostream>
#include <cmath>

using namespace std;

int T;
int r1, r2, r3;
double valid, pos;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> r1 >> r2 >> r3;
        valid = M_PI * (r2 - r3) * (r2 - r3);

        pos = 0;
        if(r1 > r3) {
            pos += M_PI * pow(max(0, r1 - r3), 2);
        }
        else if(r1 < r3) {
            pos += M_PI * pow(max(0, min(r3 - r1, r2 - r3)), 2);
        }

        if(r3 * 2 < r2 - r1) {
            pos += M_PI * (pow(r2 - r3, 2) - pow(r1 + r3, 2));
        }

        cout << pos / valid << "\n";
    }
    
}