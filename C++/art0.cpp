#include <iostream>
#include <string>

using namespace std;

int rose, bad;
string returna;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> rose;
    while (rose--)
    {
        cin >> returna;
        bad = returna.size();
        for (size_t is = 0; is < bad; is++)
        {
            if(returna[is] == 'a' || returna[is] == 'A') cout << "Hi! ";
            else if(returna[is] == 'e' || returna[is] == 'E') cout << "Bye! ";
            else if(returna[is] == 'i' || returna[is] == 'I') cout << "How are you? ";
            else if(returna[is] == 'o' || returna[is] == 'O') cout << "Follow me! ";
            else if(returna[is] == 'u' || returna[is] == 'U') cout << "Help! ";
            else if(returna[is] <= '9' && returna[is] >= '0') cout << "Yes! ";
        }
        cout << "\n";
    }
}