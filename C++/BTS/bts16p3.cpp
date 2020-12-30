#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

const int MAXN = 1e5, MOD = 1e9 + 7;
char c = '#';
string s;
ll arr[MAXN];
int idx = -1, N, cnt = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> s;
        if(s[0] != c){
            c = s[0];
            arr[++idx] = 1;
        }
        else{
            arr[idx]++;
        }
    }

    for (size_t i = 0; i <= idx; i++)
    {
        cnt += arr[i] * (arr[i] + 1) / 2 % MOD;
    }
    
    cout << cnt % MOD << "\n"; 
}