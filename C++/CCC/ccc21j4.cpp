#include <iostream>
#include <string>

using namespace std;

int L[3], M[3], S[3];
string t;
int N, l, m, s, cnt = 0;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    N = t.size();
    for (size_t i = 0; i < N; i++)
    {
        if(t[i] == 'L') l++;
        else if(t[i] == 'M') m++;
        else s++;
    }

    for (size_t i = 0; i < l; i++)
    {
        if(t[i] == 'L') L[0]++;
        else if(t[i] == 'M') M[0]++;
        else S[0]++;
    }

    for (size_t i = l; i < l + m; i++)
    {
        if(t[i] == 'L') L[1]++;
        else if(t[i] == 'M') M[1]++;
        else S[1]++;
    }

    for (size_t i = l + m; i < N; i++)
    {
        if(t[i] == 'L') L[2]++;
        else if(t[i] == 'M') M[2]++;
        else S[2]++;
    }

    while (L[0] != l || M[1] != m || S[2] != s)
    {
        int mn = min(M[0], L[1]);
        if(mn > 0){
            cnt += mn;
            M[0] -= mn;
            L[0] += mn;
            L[1] -= mn;
            M[1] += mn;
            continue;
        }

        mn = min(S[0], L[2]);
        if(mn > 0){
            cnt += mn;
            S[0] -= mn;
            L[2] -= mn;
            L[0] += mn;
            S[2] += mn;
            continue;
        }

        mn = min(S[1], M[2]);
        if(mn > 0){
            cnt += mn;
            S[1] -= mn;
            M[2] -= mn;
            M[1] += mn;
            S[2] += mn;
            continue;
        }

        cnt++;
        if(L[0] != l){
            if(L[1] > 0) {
                L[0]++;
                S[0]--;
                S[1]++;
                L[1]--;
            }
            else {
                L[0]++;
                M[0]--;
                M[2]++;
                L[2]--;
            }
            continue;
        }
        else if(M[1] != m){
            if(M[0] > 0){
                M[0]--;
                S[0]++;
                S[1]--;
                M[1]++;
            }
            else {
                M[2]--;
                L[1]--;
                M[1]++;
                L[2]++;
            }
            continue;
        }
    }
    

    cout << cnt << "\n";
}