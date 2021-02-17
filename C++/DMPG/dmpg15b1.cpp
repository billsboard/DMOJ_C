#include <iostream>
#include <string>

using namespace std;

int N, ac;
string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> s;
        if(s.size() != 10) {
            cout << "not a phone number\n";
            continue;
        }
        
        ac = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
        if(ac != 416 && ac != 647){
            cout << "not a phone number\n";
            continue;
        }

        cout << "(" << ac << ")-" << s[3] << s[4] << s[5] << "-" << s[6] << s[7] << s[8] << s[9] << "\n";
    }
}