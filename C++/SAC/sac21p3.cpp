#include <iostream>
#include <utility>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int N, P;
int m, cs, e;
string s, mxs, mns;
ll mx = -(1 << 30), mn = 1 << 30;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P;
    for (size_t i = 0; i < N; i++)
    {
        cin >> s >> m >> cs >> e;
        ll sc = (ll) (sqrt(16 * m)) + (ll) (3 * ((ll) pow(cs, P))) - 4 * e;

        if(sc > mx){
            mx = sc;
            mxs = s;
        }
        if(sc < mn){
            mn = sc;
            mns = s;
        }
    }

    cout << mxs << " " << mx << "\n";
    cout << mns << " " << mn << "\n";   
}