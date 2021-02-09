#include <iostream>

using namespace std;
typedef long long ll;

int N;

int mx(int s){
    ll res = 1;
    if(s & 1){
        int a = (s / 2) + 1;
        res = (ll) a * a;
        int b = s / 2;
        res += (ll) b * b;
    }
    else {
        int a = s / 2;
        res = (ll) a * a;
        int b = s / 2;
        res += (ll) b * b;
    }
    return res;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= 1e9; i++)
    {
        if(mx(i + 1) >= N){
            cout << i << "\n";
            return 0;
        }
    }
}