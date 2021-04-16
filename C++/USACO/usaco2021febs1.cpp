#include <iostream>
#include <set>
#include <utility>

using namespace std;
const int MAXN = 1e5 + 1, MAXX = 5003, offset = 1500;
typedef pair<int, int> pii;

int frm[MAXX][MAXX], x, y, N;
pii arr[MAXN];
bool cow[MAXX][MAXX], ins[MAXX][MAXX];
int mn, cnt = 0;
set<pii> good;

void insertCow(int x, int y){
    if(cow[x][y]) return;
    cow[x][y] = 1;
    ins[x][y] = 1;

    if(frm[x][y] == 3) good.insert(make_pair(x, y));

    frm[x + 1][y] += 1;
    frm[x - 1][y] += 1;
    frm[x][y + 1] += 1;
    frm[x][y - 1] += 1;

    if(cow[x + 1][y]){
        if(frm[x + 1][y] == 3) good.insert(make_pair(x + 1, y));
        if(frm[x + 1][y] == 4) good.erase(make_pair(x + 1, y));
    } 
    if(cow[x - 1][y]){
        if(frm[x - 1][y] == 3) good.insert(make_pair(x - 1, y));
        if(frm[x - 1][y] == 4) good.erase(make_pair(x - 1, y));
    } 
    if(cow[x][y + 1]){
        if(frm[x][y + 1] == 3) good.insert(make_pair(x, y + 1));
        if(frm[x][y + 1] == 4) good.erase(make_pair(x, y + 1));
    } 
    if(cow[x][y - 1]){
        if(frm[x][y - 1] == 3) good.insert(make_pair(x, y - 1));
        if(frm[x][y - 1] == 4) good.erase(make_pair(x, y - 1));
    } 

    cnt++;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        x += offset; y += offset;
        arr[i] = make_pair(x, y);
        cow[x][y] = 1;
        if(frm[x][y] == 3) good.insert(make_pair(x, y));

        if(ins[x][y]){
            ins[x][y] = 0;
            cnt--;
            cout << cnt << "\n";
            continue;
        }

        frm[x + 1][y] += 1;
        frm[x - 1][y] += 1;
        frm[x][y + 1] += 1;
        frm[x][y - 1] += 1;

        if(cow[x + 1][y]){
            if(frm[x + 1][y] == 3) good.insert(make_pair(x + 1, y));
            if(frm[x + 1][y] == 4) good.erase(make_pair(x + 1, y));
        } 
        if(cow[x - 1][y]){
            if(frm[x - 1][y] == 3) good.insert(make_pair(x - 1, y));
            if(frm[x - 1][y] == 4) good.erase(make_pair(x - 1, y));
        } 
        if(cow[x][y + 1]){
            if(frm[x][y + 1] == 3) good.insert(make_pair(x, y + 1));
            if(frm[x][y + 1] == 4) good.erase(make_pair(x, y + 1));
        } 
        if(cow[x][y - 1]){
            if(frm[x][y - 1] == 3) good.insert(make_pair(x, y - 1));
            if(frm[x][y - 1] == 4) good.erase(make_pair(x, y - 1));
        } 


        while (!good.empty())
        {
            pii p = *good.begin();
            if(!cow[p.first + 1][p.second]) insertCow(p.first + 1, p.second);
            else if(!cow[p.first - 1][p.second]) insertCow(p.first - 1, p.second);
            else if(!cow[p.first][p.second + 1]) insertCow(p.first, p.second + 1);
            else if(!cow[p.first][p.second - 1]) insertCow(p.first, p.second - 1);
        }

        cout << cnt << "\n";
    }



}