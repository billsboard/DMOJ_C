#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const ll MAXN = 200001, mod = 998244353;

int N, K;
string s;
ll w, a, c, wa, ac, wac, c0, ac0;
ll cnt = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    cin >> s;
    
    for (int i = N - 1; i >= 0; i--)
    {
        if(s[i] == 'C') c = (c + 1) % mod;
        else if(s[i] == 'A'){
            ac = (ac + c) % mod;
            a = (a + 1) % mod;
        }
        else if(s[i] == 'W'){
            w = (w + 1) % mod;
            wa = (wa + a) % mod;
            wac = (wac + ac) % mod;
        }
    }
    c0 = c;
    ac0 = ac;

    cnt += wac;
    for (size_t i = 1; i < K; i++)
    {
        cnt = (cnt + wac) % mod; // WAC in new portion
        cnt = (cnt + (wa * c) % mod) % mod; // WA in new, C in old
        cnt = (cnt + (w * ac) % mod) % mod; // W in new, AC in old

        ac = ((ac + ac0) % mod + (a * c) % mod) % mod;
        c = (c + c0) % mod;
    }
    
    cout << cnt % mod << "\n";
}