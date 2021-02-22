#include <iostream>
#include <utility>

using namespace std;
const int MAXN = 50, inf = 1 << 30;

struct pt
{
    int x, y;
};

struct cow{
    char d;
    int x, y;
};

const pt nsect = {inf, inf};
int N, x, y;
char c;
cow arr[MAXN];
int stp[MAXN];

pt getInterect(cow a, cow b){
    if(a.d == b.d){
        return nsect;
    }
    else if(a.d == 'N' && b.d == 'E'){
        int tx = a.x - b.x;
        if(tx < 0) return nsect;
        int ty = b.y - a.y;
        if(ty < 0 || ty == tx || ty < tx) return nsect;

        else return {a.x, b.y};
    }
    else if(a.d == 'E' && b.d == 'N'){
        int tx = b.x - a.x;
        if(tx < 0) return nsect;
        int ty = a.y - b.y;
        if(ty < 0 || tx == ty || tx < ty) return nsect;
        else return {b.x, a.y};
    }
}

int dist(pt a, pt b){
    return abs(b.x - a.x) + abs(b.y - a.y);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> c >> x >> y;
        arr[i] = {c, x, y};
    }

    for (size_t i = 0; i < N; i++)
    {
        stp[i] = inf;
        for (size_t j = 0; j < N; j++)
        {
            if (i == j) continue;
            pt res = getInterect(arr[i], arr[j]);
            if(res.x == inf || res.y == inf) continue;

            else stp[i] = min(stp[i], dist({arr[i].x, arr[i].y}, res));
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        int maxD = inf;
        for (size_t j = 0; j < N; j++)
        {
            if (i == j) continue;
            pt res = getInterect(arr[i], arr[j]);
            if(res.x == inf || res.y == inf) continue;
            int d = dist({arr[i].x, arr[i].y}, res); 

            int stpLoc;
            if(arr[j].d == 'E') stpLoc = arr[j].x + stp[j];
            else stpLoc = arr[j].y + stp[j];

            if(arr[i].d == 'E'){
                if(stpLoc > arr[i].y) maxD = min(maxD, d);
            }
            else {
                if(stpLoc > arr[i].x) maxD = min(maxD, d);
            }
        }
        
        if(maxD == inf) cout << "Infinity\n";
        else cout << maxD << "\n";
    }
}