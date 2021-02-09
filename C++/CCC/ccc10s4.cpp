#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 101;

struct edge{
    int x, y, e;
    edge(int _x, int _y, int _e){
        x = _x;
        y = _y;
        e = _e;
    }
    edge(){}
};

struct compareTo{
    bool operator()(const edge& a, const edge& b){
        return a.e < b.e;
    }
};

vector<edge> edges, noOutside;
int djs[MAXN], N, V, p, cst = 0, cst2 = 0;
unordered_map<int, edge> conv;

int store(int a, int b){
    return a << 10 | b;
}

int root(int p){
    if(djs[p] == p) return p;
    else return djs[p] = root(djs[p]);
}

void uni(int a, int b){
    int x = root(a), y = root(b);
    if(x != y){
        djs[x] = y;
    }
}

int main(){
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> V;
        vector<int> ed, cs;
        for (size_t j = 0; j < V; j++)
        {
            cin >> p;
            ed.push_back(p);
        }
        for (size_t j = 0; j < V; j++)
        {
            cin >> p;
            cs.push_back(p);
        }

        ed.push_back(ed[0]);
        cs.push_back(cs[0]);

        int u = ed[0];
        for (size_t j = 1; j <= V; j++)
        {
            int v = ed[j];
            int p = store(min(v, u), max(v, u));
            if(conv.find(p) == conv.end()){
                conv[p] = edge(i, 0, cs[j - 1]);
            }
            else{
                edge z = conv[p];
                z.y = i;
                edges.push_back(z);
                noOutside.push_back(z);
                conv.erase(p);
            }
            u = v;
        }
    }

    for (auto &&it : conv)
    {
        edges.push_back(it.second);
    }
    
    for (size_t i = 0; i <= N; i++)
    {
        djs[i] = i;
    }
    
    sort(edges.begin(), edges.end(), compareTo());
    for (size_t i = 0; i < edges.size(); i++)
    {
        edge e = edges[i];
        //cout << "(" << e.x << ", " << e.y << ", " << e.e << ") ";
        int a = root(e.x), b = root(e.y);
        if(a != b){
            uni(a, b);
            cst += e.e;
        }
    }

    for (size_t i = 0; i <= N; i++)
    {
        djs[i] = i;
    }
    
    sort(noOutside.begin(), noOutside.end(), compareTo());
    for (size_t i = 0; i < noOutside.size(); i++)
    {
        edge e = noOutside[i];
        //cout << "(" << e.x << ", " << e.y << ", " << e.e << ") ";
        int a = root(e.x), b = root(e.y);
        if(a != b){
            uni(a, b);
            cst2 += e.e;
        }
    }

    cout << min(cst, cst2) << "\n";
}