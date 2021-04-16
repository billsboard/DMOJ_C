#include <iostream>
#include <string>

using namespace std;

string s;
int T, N, K, g, b;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (size_t t = 1; t <= T; t++)
    {
        g = 0;
        b = 0;
        cin >> N >> K;
        cin >> s;
        for (size_t i = 0; i < N / 2; i++)
        {
            if(s[i] != s[N - i - 1]) g++;
            else b++;
        }

        cout << "Case #" << t << ": ";
        if(g == K) cout << 0;
        else cout << abs(K - g);
        cout << "\n";
    }
    
}