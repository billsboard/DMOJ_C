#include <iostream>

using namespace std;
const int MAXN = 1000001;

int arr[MAXN], psa[MAXN], N, K, Q, x, y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < K; i++)
    {
        cin >> x;
        arr[x]++;
    }

    psa[0] = arr[0];
    for (size_t i = 1; i < N; i++)
    {
        psa[i] = psa[i - 1] + arr[i];
    }
    

    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x >> y;
        if(x == 0) cout << psa[y];
        else cout << psa[y] - psa[x - 1];
        cout << "\n";
    }
}