#include <iostream>

using namespace std;

char x;
int C, V, N, c, v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C >> V;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        if(x == 'y'){
            v++;
            c++;
        }
        else if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            v++;
            c = 0;
        }
        else{
            v = 0;
            c++;
        }

        if(c > C || v > V){
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
}