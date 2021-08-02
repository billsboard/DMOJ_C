#include <iostream>
#include <string>

using namespace std;

string s;
int L, cnt = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    L = s.size();
    for (size_t i = 0; i < L; i++)
    {
        if(s[i] == '2'){
            if(i == L - 1 || s[i + 1] != '5') cnt++;
        }
    }

    cout << cnt << "\n";
}