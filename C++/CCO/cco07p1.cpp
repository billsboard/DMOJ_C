#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 10000, inf = 1 << 30;
const double ep = 1e-9;

struct point{
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    point(){};
};

struct compareTo{
    bool operator()(point a, point b){
        double aT = atan2l(a.y, a.x), bT = atan2l(b.y, b.x);
        if(abs(aT - bT) < ep){
            return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
        }
        return aT < bT;
    }
};

point arr[MAXN];
int N, x, y;
vector<point> stk;

int cross(point a, point b, point c){
    point ab = point(b.x - a.x, b.y - a.y), ac = point(c.x - a.x, c.y - a.y);
    return ab.x * ac.y - ab.y * ac.x;
}

void pb(point p){
    while (stk.size() >= 2)
    {
        point a = stk[stk.size() - 1], b = stk[stk.size() - 2];
        int res = cross(b, a, p);
        if(res > 0) break;
        stk.pop_back();
    }
    stk.push_back(p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        arr[i] = point(x, y);
    }

    for (size_t i = 1; i < N; i++)
    {
        if(arr[i].y < arr[0].y || (arr[i].y == arr[0].y && 
        abs(arr[i].x) < abs(arr[0].x))) swap(arr[i], arr[0]);
    }

    point tmp = point(arr[0].x, arr[0].y);
    for (size_t i = 0; i < N; i++)
    {
        arr[i].x -= tmp.x; arr[i].y -= tmp.y;
    }
    

    sort(arr + 1, arr + N, compareTo());

    stk.push_back(arr[0]);
    for (size_t i = 1; i < N; i++)
    {
        pb(arr[i]);
    }
    pb(arr[0]);
    stk.pop_back();

    int res = 0;
    point O = point(0, 0);
    for (size_t i = 1; i < stk.size(); i++)
    {
        res += cross(O, stk[i - 1], stk[i]);
    }
    res += cross(O, stk[stk.size() - 1], stk[0]);
    
    cout << (int) ((0.5 * abs(res)) / 50) << "\n";
}