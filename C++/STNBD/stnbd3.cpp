#include <iostream>
#include <string>

using namespace std;

int f1[26], f2[26], N, M, cnt;
string S, T;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> T;
    N = S.size(); M = T.size();

    for (size_t i = 0; i < N; i++)
    {
        f1[S[i] - 'a']++;
    }
    for (size_t i = 0; i < M; i++)
    {
        f2[T[i] - 'a']++;
    }

    for (size_t i = 0; i < 26; i++)
    {
        cnt += abs(f1[i] - f2[i]);
    }
    
    cout << cnt << "\n";
}