#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1e5, mod = 1e9 + 7;

struct chore{
    int a, b;
};

struct compareTo{
    bool operator()(const chore& a, const chore& b) { 
        return a.a < b.a;
    }
};

int N, a, b;
chore arr[MAXN];
ll cnt = 0, tm = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i].a >> arr[i].b;
    }

    sort(arr, arr + N, compareTo());
    
    for (size_t i = 0; i < N; i++)
    {
        chore p = arr[i];
        cnt = (cnt + (p.b * tm) + (((ll) p.b * (p.b + 1)) / 2) % mod * p.a) % mod;
        tm = (tm + ((ll) p.b * p.a)) % mod;
    }

    cout << cnt << "\n";
}