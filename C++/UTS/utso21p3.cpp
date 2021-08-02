#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e5, mod = 1e9 + 7;

stack<pii> stk;
int arr[MAXN], N;

void push_st(pii e){
    while (!stk.empty() && stk.top().first < e.first)
    {
        stk.pop();
    }
    stk.push(e);
};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        push_st(make_pair(arr[i], i));
    }

    int mxp = stk.size(), pos = 0;
    vector<pii> v;
    while (!stk.empty())
    {
        v.push_back(stk.top());
        stk.pop();
    }
    reverse(v.begin(), v.end());
    
    for (size_t i = 1; i <= mxp; i++)
    {
        if(i == 1) pos = (pos + 1) % mod;
        else{
            long long cur = 1;
            pii p = v[0];
            for (size_t j = 1; j < i; j++)
            {
                pii n = v[j];
                cur *= n.second - p.second;
                cur %= mod;
                p = n;
            }
            pos = pos + cur;
            pos %=  mod;
            
        }
    }

    cout << pos << "\n";
    
    
    
}