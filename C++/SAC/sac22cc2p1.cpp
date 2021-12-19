#include <iostream>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

const int MAXA = 101, inf = 1 << 30;
typedef pair<int, string> pis;

pis arr[MAXA];
int l = 0, A, K, C, D;
string s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> K;
    for (size_t i = 0; i < A; i++)
    {
        cin >> D >> s;
        arr[i] = make_pair(D, s);
    }

    for (size_t i = 0; i < K; i++)
    {
        cin >> C;
        for (size_t j = 0; j < A; j++)
        {
            if(l < arr[j].first && arr[j].first <= C) cout << arr[j].second << "\n";
        }
        l = C;
    }
}