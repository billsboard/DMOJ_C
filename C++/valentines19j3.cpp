#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
const int MAXS = 1e4 + 1;

string s;
int N, e[MAXS], ve[MAXS];
ll ove[MAXS], cnt = 0;

int main(){
    cin >> s;
    N = s.size();

    for (int i = N - 1; i >= 0; i--)
    {
        e[i] = e[i + 1] + (s[i] == 'e');
    }
    for (int i = N - 1; i >= 0; i--)
    {
        ve[i] = ve[i + 1];
        if(s[i] == 'v') ve[i] += e[i + 1];
    }
    for (int i = N - 1; i >= 0; i--)
    {
        ove[i] = ove[i + 1];
        if(s[i] == 'o') ove[i] += ve[i + 1];
    }

    for (size_t i = 0; i < N; i++)
    {
        if(s[i] == 'l'){
            cnt += ove[i + 1];
        }
    }
    cout << cnt << "\n";
}