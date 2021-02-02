#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll A, B;

bool prime(ll x){
    x = abs(x);
    if(x == 1) return 0;
    if(x == 2) return 1;
    int sq = sqrt(x);
    for(int i = 3; i <= sq; i+=2){
        if(!(x % i)) return 0;
    }
    return x & 1;
}

int main(){
    cin >> A >> B;

    if(prime(A - B)) cout << 2 << "\n" << A << " " << B << "\n";
    else if(A == 2){
        if(prime(B - 2)) cout << 2 << "\n" << 2 << " " << B << "\n";
        else if(prime(B + 2)) cout << 3 << "\n" << 2 << " " << B + 2 << " " << B << "\n";
        else cout << -1 << "\n"; 
    }
    else if(B == 2){
        if(prime(A - 2)) cout << 2 << "\n" << A << " " << B << "\n";
        else if(prime(A + 2)) cout << 3 << "\n" << A << " " << A + 2 << " " << B << "\n";
        else cout << -1 << "\n";
    }
    else{
        if(prime(A - 2)){
            if(prime(B - 2)) cout << 3 << "\n" << A << " " << 2 << " " << B << "\n";
            else if(prime(B + 2)) cout << 4 << "\n" << A << " " << 2 << " " << B + 2 << " " << B << "\n";
            else cout << -1 << "\n"; 
        }
        else if(prime(A + 2)){
            if(prime(B - 2)) cout << 4 << "\n" << A << " " << A + 2 << " " << 2 << " " << B << "\n";
            else if(prime(B + 2)) cout << 5 << "\n" << A << " " << A + 2 << " " << 2 << " " << B + 2 << " " << B << "\n";
            else cout << -1 << "\n"; 
        }
        else cout << -1 << "\n";
    }
}
