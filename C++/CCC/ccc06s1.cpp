#include <iostream>
#include <utility>
#include <string>

using namespace std;

int gene[5];
int A[5], B[5];
string S, T, U;
char x, y;
int N;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> T;
    for (size_t i = 0; i < 5; i++)
    {
        A[i] += S[2 * i] < 90;
        A[i] += S[2 * i + 1] < 90;
    }

    for (size_t i = 0; i < 5; i++)
    {
        B[i] += T[2 * i] < 90;
        B[i] += T[2 * i + 1] < 90;
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        gene[i] = max(A[i], B[i]);
    }

    
    
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> U;
        for (size_t j = 0; j < 5; j++)
        {
            bool dom = U[j] < 90;
            
            if(dom && !gene[j]){
                cout << "Not their baby!\n";
                goto loop;
            }
            else if(!dom && gene[j] == 2){
                cout << "Not their baby!\n";
                goto loop;
            }
        }
        cout << "Possible baby.\n";
        loop:;
    }
}