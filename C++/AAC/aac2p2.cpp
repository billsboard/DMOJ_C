#include <iostream>
#include <unordered_map>
#include <utility>
#include <set>

using namespace std;
const int MAXN = 4e3 + 1;
typedef pair<int, int> pii;

int N, arr[MAXN], mx = 1;
unordered_map<int, int> freq;
set<pii> mxvals, mx2vals;

pii mxv = make_pair(0, -1), mxv2 = make_pair(0, -1);


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }


    int cv = 0;
    for (pii p : freq)
    {
        int cur = p.second;
        if(p.second + 1 >= N){
            cv = max(cv, cur);
            continue;
        }
        
        for (size_t i = 0; i < N; i++)
        {
            if(arr[i] == p.first) continue;
            else if(arr[i] > p.first){
                int dif = arr[i] - p.first;
                if(freq.count(p.first - dif)) cur = max(cur, p.second + 2);
                else cur = max(cur, p.second + 1);
            }
        }
        cv = max(cur, cv);
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            if(!((arr[i] + arr[j]) & 1)) cv = max(cv, 2);
        }
    }
    
    
    cout << cv << "\n";
}