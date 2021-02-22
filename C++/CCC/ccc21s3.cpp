#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct person{
    int p, w, d;
};

struct compareTo{
    bool operator()(const person& a, const person& b){
        return a.p < b.p;
    }
};

const int MAXN = 200001;

person arr[MAXN];
int P[MAXN], W[MAXN], D[MAXN], N, mxp = -1, p, w, d;

ll calculate(int p){
    ll ls = 0, rs = 0;
    int idx = 0;
    while (arr[idx].p < p)
    {
        if(abs(p - arr[idx].p) <= arr[idx].d);
        else {
            ls += (ll) (abs(arr[idx].p - p) - arr[idx].d) * arr[idx].w;
        }

        idx++;
    }

    for (int i = idx; i < N; i++)
    {
        if(abs(p - arr[i].p) <= arr[i].d);
        else {
            rs += (ll) (abs(arr[i].p - p) - arr[i].d) * arr[i].w;
        }
    }
    return ls + rs;
    
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> p >> w >> d;
        mxp = max(p, mxp);
        arr[i] = {p, w, d};
    }

    if(N == 1) {
        cout << 0;
        return 0;
    }

    ll mn = 1LL << 62;

    sort(arr, arr + N, compareTo());

    int l = 0, r = mxp;

    l = 0, r = mxp;
    while(l < r){
        int mid = (l + r) / 2;

        ll r1 = calculate(mid), r2 = calculate(mid + 1);
        mn = min(mn, min(r1, r2));
        
        if(r1 < r2){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << mn << "\n";
}
