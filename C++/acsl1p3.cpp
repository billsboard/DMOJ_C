#include <iostream>

using namespace std;

const int MAXL = 160;
int N, cnt = 0, f2 = 0, f5 = 0, num[MAXL];

void mult(int n){
    int carry = 0, tmp;
    for (size_t i = 0; i < MAXL; i++)
    {
        tmp = num[i] * n + carry;
        num[i] = tmp % 10;
        carry = tmp / 10;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    num[0] = 1;

    for (size_t i = 2; i <= N; i++)
    {
        mult(i);
    }

    int idx = 159;
    while(!num[idx]) idx--;
    for (; idx >= 0; idx--)
    {
        cnt += num[idx] == 0;
    }
    
    cout << cnt << "\n";
}