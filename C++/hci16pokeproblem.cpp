#include <iostream>
#include <unordered_set>

using namespace std;
const int MAXN = 101;

unordered_set<int> sup[MAXN], res[MAXN];
int N, C, T, t1, t2, x, y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (size_t i = 0; i < C; i++)
    {
        cin >> x >> y;
        sup[x].insert(y);
        res[x].insert(y);
    }

    cin >> T;
    if(T == 1){
        cin >> t1;
        for (size_t i = 1; i <= N; i++)
        {
            if(sup[i].count(t1)){
                cout << i << "\n";
                return 0;
            }
        }

        cout << 0 << "\n";
    }
    else {
        cin >> t1 >> t2;
        int bst = 99999999;
        for (int i = 1; i <= N; i++)
        {
            if(sup[i].count(t1) && sup[i].count(t2)){
                cout << i << "\n";
                return 0;
            }
            else if((sup[i].count(t1) && !res[t2].count(i)) || (sup[i].count(t2) && !res[t1].count(i))){
                bst = min(bst, i);
            }
        }

        cout << (bst == 99999999 ? 0 : bst) << "\n";
    }
}