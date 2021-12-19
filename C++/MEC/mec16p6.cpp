#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>


using namespace std;
typedef long long ll;
const int MAXR = 41;

int C, M, R, Q, x, y, f;
ll psa[MAXR][MAXR], B, O, arr[MAXR][MAXR];
char t;
unordered_map<ll, int> mp;

ll query(int x1, int y1, int x2, int y2) {
    ll v = psa[x2][y2];
    v -= psa[x2][y1 - 1];
    v -= psa[x1 - 1][y2];
    v += psa[x1 - 1][y1 - 1];
    return v;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    fill(&arr[0][0], &arr[0][0] + sizeof(arr) / sizeof(arr[0][0]), 1);

    cin >> C >> R >> M >> Q;
    for (size_t i = 0; i < M; i++)
    {
        cin >> t >> x >> y >> f;
        if(t == 'c') {
            for (size_t j = 1; j <= R; j++)
            {
                for (size_t k = x; k <= y; k++)
                {
                    arr[j][k] *= f;
                }
            } 
        }
        else {
            for (size_t j = x; j <= y; j++)
            {
                for (size_t k = 1; k <= C; k++)
                {
                    arr[j][k] *= f;
                }
            }
        }
    }

    for (size_t i = 1; i <= R; i++)
    {
        for (size_t j = 1; j <= C; j++)
        {
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + arr[i][j];
        }
    }

    for (size_t i = 1; i <= R; i++)
    {
        for (size_t j = 1; j <= C; j++)
        {
            for (size_t k = i; k <= R; k++)
            {
                for (size_t l = j; l <= C; l++)
                {
                    ll res = query(i, j, k, l);
                    mp[res]++;
                }
            }
        }
    }

    for (size_t t = 0; t < Q; t++)
    {
        cin >> B >> O;
        
        if(B == 0) {
            if(O != 0) cout << 0 << "\n";
            else {
                cout << C * (C+1) * R * (R+1) / 4 << "\n";
            }
        }
        else if(O % B || mp.find(O / B) == mp.end()) cout << 0 << "\n";
        else {
            cout << mp[O / B] << "\n";
        }
    }    
}
