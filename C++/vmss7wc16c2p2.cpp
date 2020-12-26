#include <iostream>
#include <string>

using namespace std;

int psa[100001], N, L;
string S;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    cin >> N;
    L = S.size();
    
    for (size_t i = 1; i <= L; i++)
    {
        psa[i] = psa[i - 1] + (S[i - 1] == 'G');
    }
    
    for (size_t i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << psa[r + 1] - psa[l] << "\n";
    }
}
