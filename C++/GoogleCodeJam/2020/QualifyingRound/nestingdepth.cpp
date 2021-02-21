#include <iostream>
#include <string>

using namespace std;

int T, N, cur = 0;
string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (size_t t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        cin >> s;
        N = s.size();
        for (size_t i = 0; i < N; i++)
        {
            int x = s[i] - '0';
            if(x == cur) cout << x;
            else if(x > cur){
                while (cur < x)
                {
                    cout << "(";
                    cur++;
                }
                cout << x;
            }
            else {
                while (cur > x)
                {
                    cout << ")";
                    cur--;
                }
                cout << x;
            }
        }

        while (cur)
        {
            cout << ")";
            cur--;
        }
        
        cout << "\n";   
    }
    
}