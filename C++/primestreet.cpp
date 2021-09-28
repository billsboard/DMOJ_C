#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXK = 100000 + 5;
const ll inf = 1LL << 62;

ll pri[MAXK], com[MAXK], mn = inf, N;
int K, st = 0;

bool isPrime(int n) {
    for (size_t i = 1; i < MAXK; i++)
    {
        if(pri[i] == 0 || pri[i] * pri[i] > n) break;
        else if(!(n % pri[i])) return false;
    }
    return true;
}

void genpri() {
    pri[1] = 2;
    int i = 2, num = 3;
    while (i <= 100002)
    {
        //cout << i << " " << num << " " << isPrime(num) << endl;
        if(isPrime(num)) {
            pri[i] = num;
            i++;
        }
        num += 2;
    }
}

void gencom() {
    com[1] = 4;
    int i = 2, num = 6;
    while (i <= 100002)
    {
        if(!isPrime(num)) {
            com[i++] = num;
        }
        num++;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    genpri();
    gencom();

    for (size_t i = 1; i <= 100001; i++)
    {
        pri[i] = pri[i - 1] + pri[i];
        com[i] = com[i - 1] + com[i];
    }
    

    for (size_t i = 1; i <= 100000; i++)
    {
        if(i + K - 1 > 100000) break;
        ll a = pri[i + K - 1] - pri[i - 1], b = com[i + K - 1] - com[i - 1];
        if(a < K) continue;


        if(mn > abs(a - N - b)) {
            mn = abs(a - N - b);
            st = i;
        }
    }
    
    cout << st << "\n";
}