#include <iostream>

using namespace std;

int N, a, b;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    
}
