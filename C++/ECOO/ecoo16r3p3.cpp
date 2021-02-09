#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;
const int MAXL = 2001, inf = 1 << 30;

int N, dp[MAXL];
string s;
unordered_set<string> dict;

void recurse(int p){
    string t = s.substr(0, p + 1);
    if(dict.count(t)){
        dp[p] = 0;
        return;
    }
    if(dp[p] == inf){
    for (int i = p; i >= 0; i--)
        {
            string x = s.substr(i, p - i + 1);
            if(dict.count(x)){
                recurse(i - 1);
                dp[p] = min(dp[p], dp[i - 1] + 1);
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> s;
        dict.insert(s);
    }

    for (size_t i = 0; i < 10; i++)
    {
        cin >> s;
        fill(&dp[0], &dp[0] + sizeof(dp) / sizeof(dp[0]), inf);
        recurse(s.size() - 1);
        cout << dp[s.size() - 1] << "\n";
    }
}