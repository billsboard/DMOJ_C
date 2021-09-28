#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 4 * 2e5 + 5;


struct event {
    int t, x, y;
    // t: 0 start roomba, 1 cord, 2 end roomba;
};



vector<event> eves;
int N, M, xi, xj, yi, yj, seg[4 * MAXN], x, y;
ll cnt = 0;
vector<int> yvals;

void update(int i, int v, int rl, int rr, int p) {
    if(rl == rr) {
        seg[p] += v;
    }
    else {
        int mid = (rl + rr) / 2;
        if(i <= mid) update(i, v, rl, mid, p * 2);
        else update(i, v, mid + 1, rr, p * 2 + 1);
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}

int query(int ql, int qr, int rl, int rr, int p) {
    if(rl > qr || rr < ql) return 0;
    else if(ql <= rl && rr <= qr) return seg[p];
    else {
        int mid = (rl + rr) / 2;
        return query(ql, qr, rl, mid, p * 2) + 
        query(ql, qr, mid + 1, rr, p * 2 + 1);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    yvals.push_back(0);
    
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        eves.push_back({0, 0, y});
        eves.push_back({2, x, y});

        yvals.push_back(y);
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y;
        eves.push_back({1, x, y});
        
        yvals.push_back(y);
    }

    sort(yvals.begin(), yvals.end());

    for (size_t i = 0; i < eves.size(); i++)
    {
        eves[i].y = lower_bound(yvals.begin(), yvals.end(), eves[i].y) - yvals.begin();
    }

    sort(eves.begin(), eves.end(), [](const event& a, const event& b) -> bool{
        if(a.x == b.x) return a.t < b.t;
        return a.x < b.x;
    });

    for(event e : eves) {
        //cout << e.t << " " << e.x << " " << e.y << "\n";
        if(e.t == 0) {
            update(e.y, 1, 1, MAXN - 1, 1);
        }
        else if(e.t == 1) {
            cnt += query(0, e.y, 1, MAXN - 1, 1);
        }
        else {
            update(e.y, -1, 1, MAXN - 1, 1);
        }
    }
    
    cout << cnt << "\n";
}