#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;
typedef long long ll;

const int MAXN = 400000;
int N, arr[MAXN];
ll cnt = 0, h;
stack<ll> stk;
unordered_map<ll, ll> freq;

void pushVal(ll h){
    while (!stk.empty() && stk.top() < h)
    {
        freq[stk.top()]--;
        stk.pop();
        cnt++;
    }

    freq[h]++;
    cnt += freq[h] - 1;
    stk.push(h);
    if(freq[h] > 1 && stk.size() == freq[h]) cnt--;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> h;
        pushVal(h);
        cnt += min((int) stk.size() - 1, 1);
    }

    cout << cnt << "\n";
}