#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;
const int MAXN = 100001;
typedef pair<int, int> pii;

int N, T, idx = 0, u, v, t;
unordered_map<int, int> djs;
pii arr[MAXN];

int root(int p) {
    if(djs.find(p) == djs.end()) {
        djs[p] = p;
        return djs[p];
    }
    else if(djs[p] == p) return p;
    return djs[p] = root(djs[p]);
}

void uni(int a, int b) {
    int x = root(a), y = root(b);
    if(x != y) {
        djs[x] = y;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;
        djs.clear();
        idx = 0;
        for (size_t i = 0; i < N; i++)
        {
            cin >> u >> v >> t;
            if(t) {
                uni(u, v);
            }
            else {
                arr[idx++] = make_pair(u, v);
            }
        }

        bool ok = true;

        for (size_t i = 0; i < idx; i++)
        {
            pii p = arr[i];
            if(root(p.first) == root(p.second)) {
                ok = false;
                break;
            }
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
}