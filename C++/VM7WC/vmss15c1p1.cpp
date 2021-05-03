#include <iostream>
#include <math.h>

using namespace std;

int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int sq = sqrt(N);

    while (N % sq)
    {
        sq++;
    }

    cout << sq * 2 + (N / sq) * 2 << "\n"; 
}