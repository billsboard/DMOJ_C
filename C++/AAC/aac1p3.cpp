#include <iostream>

using namespace std;
const int MAXN = 1e6;


int N, X;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> X;

    if(X == N){
        cout << 1;
        for (size_t i = 1; i < N; i++)
        {
            cout << " " << 1;
        }
        cout << "\n";
        return 0;
    }

    if(X > N || X == N - 1 || ((X + N) & 1)) {
        cout << -1 << "\n";
        return 0;
    }
    cout << 1;
    for (size_t i = 1; i <= X; i++)
    {
        cout << " " << 1;
    }
    bool par = true;
    for (size_t i = X + 1; i < N; i++)
    {
        cout << " " << 1 + par;
        par = !par;
    }
    cout << "\n";
}