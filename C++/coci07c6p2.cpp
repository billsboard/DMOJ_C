#include <iostream>

using namespace std;

int wait(int p);
int R[1001], G[1001];
int N, L, t = 0;

int main(){
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        cin >> R[p] >> G[p];
    }

    for (int i = 1; i <= L; i++)
    {
        t++;
        t += wait(i);
    }

    cout << t << "\n";
    return 0;
}

int wait(int p){
    if(R[p] == 0) return 0;
    int r = t % (R[p] + G[p]);
    if(r < R[p]) return R[p] - r;
    return 0;
}