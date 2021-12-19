#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 3e6 + 1, MAXL = 21;

int N, K, arr[MAXN], freq[21];
ll cnt;
string s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (size_t i = 1; i <= N; i++)
    {
        cin >> s;
        arr[i] = s.size();
    }
    

    for (size_t i = 1; i <= K; i++)
    {
        freq[arr[i]]++;
    }

    for (size_t i = K + 1; i <= N; i++)
    {
        freq[arr[i]]++;
        int x = arr[i - K];
        cnt += freq[x] - 1;
        freq[x]--;
    }

    for (size_t i = N - K + 1; i < N; i++)
    {
        freq[arr[i]]--;
        cnt += freq[arr[i]];
    }
    
    cout << cnt << "\n";
}