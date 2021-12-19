#include <iostream>
#include <string>

using namespace std;
const int MAXN = 5001;

int N, freq[3], ssa[3][MAXN];
string S, T;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> S >> T;

    for (size_t i = 0; i < N; i++)
    {
        freq[S[i] - 'a']++;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (size_t j = 0; j < 3; j++)
        {
            ssa[j][i] = ssa[j][i + 1];
        }
        ssa[T[i] - 'a'][i]++;
    }
        
    
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(freq[j] > 0 && T[i] != (j + 'a')) {
                for (size_t k = 0; k < 3; k++)
                {
                    if(j == k) continue;
                    if((N - i - 1) - ssa[k][i + 1] < freq[k]) {
                        goto endLoop;
                    }
                }
                
                cout << (char) (j + 'a');
                freq[j]--;
                break;
            }
                    
            endLoop:;
        }
    }
    cout << "\n";
}
