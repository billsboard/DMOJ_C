#include <iostream>
#include <string>

using namespace std;
int N, mx = -1, x;
string t, s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        cin >> s >> x;
        if(x > mx){
            mx = x;
            t = s;
        }
    }

    cout << t << "\n";
}