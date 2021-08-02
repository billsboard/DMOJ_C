#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAXN = 5 * 1e5 + 1, mod = 2021, inf = 1 << 30;

int dist[MAXN], fib[MAXN], N;

int f(int n){
    if(n == 1 || n == 2) return fib[n] = 1;
    if(fib[n] != 0) return fib[n];
    else {
        return fib[n] = (f(n - 1) + f(n - 2)) % mod;
    }
}

void bfs(){
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if(v - 1 > 0 && dist[v] + 1 < dist[v - 1]){
            dist[v - 1] = dist[v] + 1;
            q.push(v - 1);
        }
        if(v + 1 <= N && dist[v] + 1 < dist[v + 1]){
            dist[v + 1] = dist[v] + 1;
            q.push(v + 1);
        }

        int jmp = f(v) + (v % 50);
        if(v - jmp > 0 && dist[v - jmp] > dist[v] + 1){
            dist[v - jmp] = dist[v] + 1;
            q.push(v - jmp);
        }
        if(v + jmp <= N && dist[v + jmp] > dist[v] + 1){
            dist[v + jmp] = dist[v] + 1;
            q.push(v + jmp);
        }


    }
    
}

int main(){
    cin >> N;
    fill(&dist[0], &dist[0] + sizeof(dist) / sizeof(dist[0]), inf);
    bfs();
    cout << dist[N] << "\n";
}