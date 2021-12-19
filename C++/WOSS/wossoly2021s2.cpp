#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 1;

int R, B, G, BG, BR, RG, N;
ll cnt = 0;
char top[MAXN], bot[MAXN], l[MAXN], r[MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> top[i];
    }
    for (size_t i = 1; i <= N; i++)
    {
        cin >> r[i];
    }
        for (size_t i = 1; i <= N; i++)
    {
        cin >> bot[i];
    }
        for (size_t i = 1; i <= N; i++)
    {
        cin >> l[i];
    }

    for (size_t i = 1; i <= N; i++)
    {
        if(top[i] == 'R' && bot[i] == 'R') R++;
        else if(top[i] == 'B' && bot[i] == 'B') B++;
        else if(top[i] == 'G' && bot[i] == 'G') G++;
        else if((top[i] == 'R' && bot[i] == 'B') ||
         (top[i] == 'B' && bot[i] == 'R')) BR++;
        else if((top[i] == 'B' && bot[i] == 'G') ||
         (top[i] == 'G' && bot[i] == 'B')) BG++;
        else if((top[i] == 'R' && bot[i] == 'G') ||
         (top[i] == 'G' && bot[i] == 'R')) RG++;
    }

    for (size_t i = 1; i <= N; i++)
    {
        if(l[i] == 'R' && r[i] == 'R') cnt += BG;
        else if(l[i] == 'B' && r[i] == 'B') cnt += RG;
        else if(l[i] == 'G' && r[i] == 'G') cnt += BR;
        else if((l[i] == 'R' && r[i] == 'B') ||
         (l[i] == 'B' && r[i] == 'R')) cnt += G + RG + BG;
        else if((l[i] == 'B' && r[i] == 'G') ||
         (l[i] == 'G' && r[i] == 'B')) cnt += R + BR + RG;
        else if((l[i] == 'R' && r[i] == 'G') ||
         (l[i] == 'G' && r[i] == 'R')) cnt += B + BG + BR;
    }
    
    cout << cnt << "\n";
}
