#include <iostream>

using namespace std;

int A[] = {'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C', 'A', 'B', 'C'}, 
    B[] = {'B', 'A', 'B', 'C', 'B', 'A', 'B', 'C', 'B', 'A', 'B', 'C'},
    C[] = {'C', 'C', 'A', 'A', 'B', 'B', 'C', 'C', 'A', 'A', 'B', 'B'},
    idx = 0, a = 0, b = 0, c = 0, N;
char l;    

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> l;
        if(A[idx] == l) a++;
        if(B[idx] == l) b++;
        if(C[idx] == l) c++;
        idx = (idx + 1) % 12;
    }
    
    int M = max(a, max(b, c));
    cout << M << "\n";

    if(a == M) cout << "Adrian\n";
    if(b == M) cout << "Bruno\n";
    if(c == M) cout << "Goran\n";
}