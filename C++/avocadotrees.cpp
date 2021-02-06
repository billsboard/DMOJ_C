#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e6;

int N, Q, H, psa[MAXN + 1], x, y, mx = -1;
pii arr[MAXN + 1];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q >> H;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (size_t i = 1; i <= N; i++)
    {
        if(arr[i].first <= H){
            psa[i] = psa[i - 1] + arr[i].second;
        }
        else{
            psa[i] = psa[i - 1];
        }
    }

    for (size_t i = 0; i < Q; i++)
    {
        cin >> x >> y;
        mx = max(mx, psa[y] - psa[x - 1]);
    }
    cout << mx << "\n";
}