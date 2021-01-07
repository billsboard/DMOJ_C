#include <iostream>
#include <math.h>

using namespace std;

int N, K;

void printNum(int n){
    cout << n << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> K;
        while (!(K & 1))
        {
            printNum(2);
            K = K >> 1;
        }
        for (size_t i = 3; i <= sqrt(K); i++)
        {
            while (!(K % i))
            {
                printNum(i);
                K /= i;
            }
        }

        if(K != 1) printNum(K);
        cout << "\n";
    }
}