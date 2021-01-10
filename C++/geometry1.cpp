#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int N;
double X1, X2, X3, Y1, Y2, Y3, a, b, c, s, A;

double pythag(double X1, double Y1, double X2, double Y2){
    double x = abs(X1 - X2), y = abs(Y1 - Y2);
    return sqrt(x * x + y * y);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
        a = pythag(X1, Y1, X2, Y2); b = pythag(X1, Y1, X3, Y3); c = pythag(X2, Y2, X3, Y3);
        s = (a + b + c) / 2;
        A = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("%.2f %.2f\n", A, a + b + c); 
    }
    
}
