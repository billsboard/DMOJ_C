#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int N, Q, a, b, z;
char c;
unordered_map<int, unordered_set<int>> x, y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (size_t i = 0; i < N; i++)
    {
        cin >> a >> b;
        x[a].insert(b);
        y[b].insert(a);
    }

    for (size_t i = 0; i < Q; i++)
    {
        cin >> z;
        if(z == 1){
            cin >> a >> b;
            if(x[a].find(b) != x[a].end()) cout << "salty\n";
            else cout << "bland\n";
        }
        else if(z == 2){
            cin >> c >> a;
            if(c == 'X'){
                cout << x[a].size();
            }
            else {
                cout << y[a].size();
            }
            cout << "\n";
        }
    }
}