#include <iostream>
#include <unordered_set>

using namespace std;
const int MAXN = 100001, MAXM = 1000001;

struct edge{
    int x, y, v;
    edge(int _x, int _y, int _v){
        x = _x; 
        y = _y;
        v = _v;
    }
    edge(){}
};

int djs[MAXN], sz[MAXN], N, M, x, y;
unordered_set<int>  res;
edge arr[MAXM];

int root(int p){
    if(djs[p] == p) return p;
    else return djs[p] = root(djs[p]); 
}

void uni(int a, int b){
    int x = root(a), y = root(b);
    if(x != y){
        if(sz[x] < sz[y]) swap(x, y);
        djs[y] = x;
        sz[x] += sz[y];
    }
}

void mst(){
    for (size_t i = 0; i < M; i++)
    {
        edge e = arr[i];
        int x = root(e.x), y = root(e.y);
        if(x != y){
            res.insert(e.v);
            uni(e.x, e.y);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        djs[i] = i;
        sz[i] = 1;
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> x >> y;
        arr[i] = edge(x, y, i + 1);
    }

    mst();

    if(res.size() < N - 1){
        cout << "Disconnected Graph\n";
        return 0;
    }
    for(int i : res){
        cout << i << "\n";
    }
}