#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXS = 1e4 + 1;

int N, d[MAXS], oj[MAXS];
ll moj[MAXS], cnt = 0;

ll f(string s){
    N = s.size();
    cnt = 0;
    d[N] = 0;
    oj[N] = 0;
    moj[N] = 0;
    
    for (int i = N - 1; i >= 0; i--)
    {
        d[i] = d[i + 1] + (s[i] == 'J');
    }
    for (int i = N - 1; i >= 0; i--)
    {
        oj[i] = oj[i + 1];
        if(s[i] == 'O') oj[i] += d[i + 1];
    }
    for (int i = N - 1; i >= 0; i--)
    {
        moj[i] = moj[i + 1];
        if(s[i] == 'M') moj[i] += oj[i + 1];
    }

    for (size_t i = 0; i < N; i++)
    {
        if(s[i] == 'D'){
            cnt += moj[i + 1];
        }
    }
    return cnt;
}