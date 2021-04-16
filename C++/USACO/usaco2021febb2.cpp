#include <iostream>
#include <set>
#include <utility>

using namespace std;
const int MAXX = 1002, MAXN = 1e5 + 1;
typedef pair<int, int> pii;

struct cow {
    int x, y;
};

int ins = 0, N, farm[MAXX][MAXX], x, y, com = 0;
bool pres[MAXX][MAXX];
set<pii> good; 

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        pres[x][y] = 1;
        if(farm[x][y] == 3) good.insert(make_pair(x, y));
        farm[x + 1][y] += 1;
        farm[x][y + 1] += 1;
        if(x - 1 >= 0) farm[x - 1][y] += 1;
        if(y - 1 >= 0) farm[x][y - 1] += 1;


        if(farm[x + 1][y] == 3 && pres[x + 1][y]){
            good.insert(make_pair(x + 1, y));
        }
        else if(farm[x + 1][y] == 4 && pres[x + 1][y]){
            good.erase(make_pair(x + 1, y));
        } 

        if(farm[x][y + 1] == 3 && pres[x][y + 1]){
            good.insert(make_pair(x, y + 1));
        }
        else if(farm[x][y + 1] == 4 && pres[x][y + 1]){
            good.erase(make_pair(x, y + 1));
        } 

        if(x - 1 >= 0 && pres[x - 1][y]){
            if(farm[x - 1][y] == 3) good.insert(make_pair(x - 1, y));
            else if(farm[x - 1][y] == 4) good.erase(make_pair(x - 1, y));
        }

        if(y - 1 >= 0 && pres[x][y - 1]){
            if(farm[x][y - 1] == 3) good.insert(make_pair(x, y - 1));
            else if(farm[x][y - 1] == 4) good.erase(make_pair(x, y - 1));
        }
        
    
        cout << good.size() << "\n";
    }
}