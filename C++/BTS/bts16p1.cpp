#include <iostream>
#include <string>

using namespace std;

string s;
int u = 0, l = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);

    for (size_t i = 0; i < s.length(); i++)
    {
        if('a' <= s[i] && s[i] <= 'z') l++;
        else if('A' <= s[i] && s[i] <= 'Z') u++;
    }

    if(l > u){
        for (size_t i = 0; i < s.length(); i++)
        {
            s[i] = tolower(s[i]);
        }
    }
    else if(u > l){
        for (size_t i = 0; i < s.length(); i++)
        {
            s[i] = toupper(s[i]);
        }
    }

    cout << s << "\n";
}