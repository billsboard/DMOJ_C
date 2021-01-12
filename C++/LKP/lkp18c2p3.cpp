#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100;
int N, M, x, y, cnt;
pii arr[MAXN], p1, p2, p3;

ll cross(pii a, pii b, pii c){
    pii ab = make_pair(b.first - a.first, b.second - a.second);
    pii ac = make_pair(c.first - a.first, c.second - a.second);
    return ((ll) ab.first * ac.second) - ((ll) ab.second * ac.first);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y; p1 = make_pair(x, y);
        cin >> x >> y; p2 = make_pair(x, y);
        cin >> x >> y; p3 = make_pair(x, y);
        cnt = 0;

        for (size_t j = 0; j < N; j++)
        {
            pii p = arr[j];
            ll res1 = abs(cross(p, p1, p2) + cross(p, p2, p3) + cross(p, p3, p1));
            ll res2 = abs(cross(p, p1, p2)) + abs(cross(p, p2, p3)) + abs(cross(p, p3, p1));
            cnt += res1 == res2;
        }
        cout << cnt << "\n";
    }
}