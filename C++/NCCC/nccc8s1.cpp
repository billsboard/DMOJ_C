#include <iostream>
#include <string>
#include <set>

using namespace std;

string s, t;
set<string> res;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> s;
    for (size_t i = 0; i < t.size(); i++)
    {
        char add = t[i];
        for (size_t j = 0; j <= s.size(); j++)
        {
            string s2 = s;
            s2.insert(s2.begin() + j, add);
            res.insert(s2);
        }
    }

    for(int i = 0; i < s.size(); i++){
        string s2 = string(s);
        s2.erase(s2.begin() + i);
        res.insert(s2);
    }

    for (size_t i = 0; i < t.size(); i++)
    {
        char cng = t[i];
        for (size_t j = 0; j < s.size(); j++)
        {
            string s2 = string(s);
            s2[j] = cng;
            res.insert(s2);
        }
        
    }

    res.insert(s);
    res.erase(s);
    for(string x : res){
        cout << x << "\n";
    }
}