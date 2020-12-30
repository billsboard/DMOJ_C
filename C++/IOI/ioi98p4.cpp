#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

struct event {
    int x, y1, y2, t;
    event(int x, int y1, int y2, int t) : x(x), y1(y1), y2(y2), t(t){}
};

struct compareTo {
    bool operator()(event const& a, event const& b){
        return a.x < b.x;
    }
};

vector<event> eX, eY;
set<int> sX, sY;
int N, P, x1, x2, y1, y2;
const int inf = 1 << 30;
unordered_map<int, int> mX, mY;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    P = N * 2;

    for (size_t i = 0; i < N; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        event e1 = event(x1, y1, y2, 1), e2(x2, y1, y2, -1);
        mY[y1] = 0; mY[y2] = 0;
        eX.push_back(e1); eX.push_back(e2);
        sY.insert(y1); sY.insert(y2);

        event e3 = event(y1, x1, x2, 1), e4(y2, x1, x2, -1);
        mX[x1] = 0; mX[x2] = 0;
        eY.push_back(e3); eY.push_back(e4);
        sX.insert(x1); sX.insert(x2);
    }

    sort(eX.begin(), eX.end(), compareTo());
    sort(eY.begin(), eY.end(), compareTo());

    mY[inf] = 0;
    mX[inf] = 0;
    sX.insert(inf);
    sY.insert(inf);
    mY[-inf] = 0;
    mX[-inf] = 0;
    sX.insert(-inf);
    sY.insert(-inf);

    int per = 0, prevX = -1, v = 0, prevV = 0;
    for (size_t i = 0; i < N * 2; i++)
    {
        event e = eX[i];
        v = 0, prevV = 0;
        for(int y : sY){
            if(prevV == 0 && v > 0) per += abs(e.x - prevX);
            else if(prevV > 0 && v == 0) per += abs(e.x - prevX);
            
            prevV = v;
            v += mY[y];
        }
        

        mY[e.y1] += e.t;
        mY[e.y2] -= e.t;
        prevX = e.x;
    }

    int prevY = -1;
    v = 0, prevV = 0;
    for (size_t i = 0; i < N * 2; i++)
    {
        event e = eY[i];
        v = 0, prevV = 0;
        for(int x : sX){
            if(prevV == 0 && v > 0) per += abs(e.x - prevY);
            else if(prevV > 0 && v == 0) per += abs(e.x - prevY);
                
            prevV = v;
            v += mX[x];
        }
        

        mX[e.y1] += e.t;
        mX[e.y2] -= e.t;
        prevY = e.x;
    }

    cout << per << "\n";
}
