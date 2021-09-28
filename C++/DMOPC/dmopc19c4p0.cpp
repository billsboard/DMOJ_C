#include <iostream>
#include <string>

using namespace std;

string s, t;
int cnt = 0, N;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    N = s.size();
    for (size_t i = 0; i < N; i++)
    {
        cnt += (s[i] != t[i]);
    }
    cout << "LARRY IS " << (cnt == 1 ? "SAVED" : "DEAD") << "!\n";
}