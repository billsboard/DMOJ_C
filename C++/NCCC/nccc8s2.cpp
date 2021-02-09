#include <iostream>
#include <string>

using namespace std;
const int mod = 1e9 + 7;

int arr[26];
string s;
int N;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    N = s.size();
    for (size_t i = 0; i < N; i++)
    {
        arr[s[i] - 'a']++;
    }

    long long res = 1;
    for (size_t i = 0; i < 26; i++)
    {
        res = res * (arr[i] + 1) % mod;
    }

    cout << res << "\n";
}