#include <iostream>
#include <utility>

using namespace std;


int avail[8], need[8], cnt;
int give[8][9] = {
    {0, -1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, -1, 0, 0, 0, 0, 0, 0},
    {0, 2, -1, 0, 0, 0, 0, 0, 0},
    {0, 1, 2, 3, -1, 0, 0, 0, 0},
    {0, 4, -1, 0, 0, 0, 0, 0, 0},
    {0, 1, 4, 5, -1, 0, 0, 0, 0}, 
    {0, 2, 4, 6, -1, 0, 0, 0, 0},
    {0, 1, 2, 3, 4, 5, 6, 7, -1}
};
/* 
O- 0, O+ 1, A- 2, A+ 3, B- 4, B+ 5, AB- 6, AB+ 7
*/ 

int giveStatus(int a, int n){
    if(a == n) return 0;
    else if(a > n) return 1;
    return -1;
}

void giveTo(int t){
    int n = need[t];
    int idx = 8;
    while (give[t][idx] != -1)
    {
        idx--;
    }
    idx--;
    for (int i = idx; i >= 0; i--)
    {
        int v = give[t][i];
        int a = avail[v];
        int s = giveStatus(a, n);
        if(s == -1){
            n -= a;
            cnt += a;
            avail[v] = 0;
        }
        else if(s == 0){
            n = 0;
            cnt += a;
            avail[v] = 0;
            return;
        }
        else if(s == 1){
            a -= n;
            avail[v] = a;
            cnt += n;
            n = 0;
            return;
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (size_t i = 0; i < 8; i++)
    {
        cin >> avail[i];
    }
    for (size_t i = 0; i < 8; i++)
    {
        cin >> need[i];
    }

    for (size_t i = 0; i < 8; i++)
    {
        int s = giveStatus(avail[i], need[i]);
        if(s == -1){
            need[i] -= avail[i];
            cnt += avail[i];
            avail[i] = 0;
        }
        else if(s == 0){
            need[i] = 0;
            cnt += avail[i];
            avail[i] = 0;
        }
        else {
            avail[i] -= need[i];
            cnt += need[i];
            need[i] = 0;
        }
    }

    giveTo(1);
    giveTo(2);
    giveTo(4);
    giveTo(3);
    giveTo(5);
    giveTo(6);
    giveTo(7);
    cout << cnt << "\n";
}