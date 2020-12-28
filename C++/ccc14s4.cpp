#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct event {
    int x, y1, y2, k;
    event(int x, int y1, int y2, int k) : x(x), y1(y1), y2(y2), k(k) {}
};

struct compareTo {
    bool operator()(event const& a, event const& b){
        return a.x < b.x;
    }
};

vector<event> eve;
int N, T, x1, x2, y1, y2, k;
set<int> ySet;
unordered_map<int, int> tFact;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        event e1 = event(x1, y1, y2, k), e2 = event(x2, y1, y2, -k);
        eve.push_back(e1); eve.push_back(e2);
        ySet.insert(y1); ySet.insert(y2);
        tFact[y1] = 0; tFact[y2] = 0;
    }

    sort(eve.begin(), eve.end(), compareTo());

    long long tot = 0;
    int prevX = -1;
    for (size_t i = 0; i < N * 2; i++)
    {
        event e = eve[i];
        int cK = 0, prevY = -1;
        if(prevX != -1){
            for(int y : ySet){
                if(cK >= T && prevY != -1){
                    tot += (long long) (y - prevY) * (e.x - prevX);
                }
                cK += tFact[y];
                prevY = y;
            }
        }

        tFact[e.y1] += e.k;
        tFact[e.y2] -= e.k;
        prevX = e.x;
    }

    cout << tot << "\n";
}
