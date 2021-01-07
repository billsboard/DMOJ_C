#include <iostream>
#include <unordered_set>

using namespace std;
typedef long long ll;

const int MAXN = 5000, MAXA = 1e6 + 1;
bool val[MAXA * 2];
int arr[MAXN], N, a;
unordered_set<ll> res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> a;
        val[a] = true;
        arr[i] = a;
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            if(val[arr[i] + arr[j]]){
                res.insert(((ll) min(arr[i], arr[j]) << 32) | max(arr[i], arr[j]));
            }
        }
    }
    cout << (res.size() == 0 ? -1 : res.size()) << "\n";
}