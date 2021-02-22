#include <iostream>
#include <set>

using namespace std;

int M, N, K, x;
char t;

set<int> r, c;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (size_t i = 0; i < K; i++)
    {
        cin >> t >> x;
        if(t == 'R'){
            if(r.count(x)) r.erase(x);
            else r.insert(x);
        }
        else {
            if(c.count(x)) c.erase(x);
            else c.insert(x);
        }
    }

    int ans = M * r.size() + N * c.size() - r.size() * c.size() * 2;
    cout << ans << "\n";
}