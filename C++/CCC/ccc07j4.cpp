#include <iostream>
#include <string>

using namespace std;

int a[100], b[100], M, N;
string s, t;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    getline(cin, s);
    getline(cin, t);
    M = s.size(); N = t.size();

    for (size_t i = 0; i < M; i++)
    {
        if(s[i] == ' ') continue;
        a[s[i]]++;
    }

    for (size_t i = 0; i < N; i++)
    {
        if(t[i] == ' ') continue;
        b[t[i]]++;
    }

    for (size_t i = 0; i < 100; i++)
    {
        if(a[i] != b[i]){
            cout << "Is not an anagram.\n";
            return 0;
        }
    }

    cout << "Is an anagram.\n";
}