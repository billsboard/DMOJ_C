#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 200001;

bool on[MAXN];
int swi[MAXN], N, M, tmp[MAXN], oncnt = 0, y;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> y;
        on[i] = y;
        oncnt += on[i];
    }
    for (size_t i = 1; i <= M; i++)
    {
        cin >> swi[i];
    }

    fill(tmp, tmp + N + 1, oncnt);
    tmp[0] = oncnt;
    for (size_t i = 1; i <= M; i++)
    {
        if(on[swi[i]]) tmp[i] = tmp[i - 1] - 1;
        else tmp[i] = tmp[i - 1] + 1;
        on[swi[i]] = !on[swi[i]];
    }
    

    for (size_t i = 1; i <= M; i++)
    {
        //cout << tmp[i] << " ";
    }
    
    if(oncnt == 0){
        cout << 0 << "\n";
        return 0;
    }

    for (size_t i = 1; i <= M; i++)
    {
        if(i >= tmp[i]){
            cout << i << "\n";
            return 0;
        }
    }

    cout << tmp[M] << "\n";
}