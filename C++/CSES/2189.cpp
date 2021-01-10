#include <iostream>

using namespace std;

int N, X1, X2, X3, Y1, Y2, Y3;
double m, ep = 1e-6;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
        m = (double) (Y2 - Y1) / (X2 - X1);
        double pt = m * X3 - m * X1 + Y1;
        if(X1 < X2){
            if(abs(pt - Y3) < ep) cout << "TOUCH\n";
            else if(pt > Y3) cout << "RIGHT\n";
            else if(pt < Y3) cout << "LEFT\n";
        }
        else if(X2 < X1){
            if(abs(pt - Y3) < ep) cout << "TOUCH\n";
            else if(pt < Y3) cout << "RIGHT\n";
            else if(pt > Y3) cout << "LEFT\n";
        }
        else {
            if(Y1 < Y2 && X3 < X2) cout << "LEFT\n";
            else if(Y1 > Y2 && X3 > X2) cout << "LEFT\n";
            else if(X3 == X2) cout << "TOUCH\n";
            else cout << "RIGHT\n";
        }
    }
    
}