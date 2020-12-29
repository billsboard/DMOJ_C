#include <iostream>

using namespace std;

int N, D, w, n, d;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D;
    w = N / D;
    n = N - (N / D) * D;
    d = D;

    while (true)
    {
        for (size_t i = 2; i <= n; i++)
        {
            if(!(n % i) && !(d % i)){
                n /= i;
                d /= i;
                goto loop;
            }
        }

        break;
        loop:;
    }

    if(w){
        cout << w << " ";
    }
    if(n){
        cout << n << "/" << d;
    }
    cout << endl;

}