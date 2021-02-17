#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;
const int MAXN = 500010;
typedef long long ll;

int N, arr[MAXN], x;
stack<int> stk;
ll cnt = 0;
unordered_map<int, int> freq;


void pushStk(int p){
    while (!stk.empty() && stk.top() < p)
    {
        cnt++;
        freq[stk.top()]--;
        stk.pop();
    }

    freq[p]++;
    cnt += freq[p] - 1;
    stk.push(p);
    if(freq[p] == stk.size() && freq[p] > 1) cnt--;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        pushStk(x);
        cnt += min((int) stk.size() - 1, 1);
    }
    
    cout << cnt << "\n";
}