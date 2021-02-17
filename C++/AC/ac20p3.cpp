#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAXL = 5 * 1e5;

int sFreq[26], tFreq[26];
vector<int> iTable[26];
string s, T;
int N, M, dp[MAXL];


int main(){
    cin >> N >> M;
    cin >> s >> T;
    for (size_t i = 0; i < N; i++)
    {
        sFreq[s[i] - 'a']++;
        iTable[s[i] - 'a'].push_back(i);
    }
    for (size_t i = 0; i < M; i++)
    {
        tFreq[T[i] - 'a']++;
        if(sFreq[T[i] - 'a'] == 0){
            cout << -1 << "\n";
            return 0;
        }
    }

    int lIdx = -1, roll = 0;
    for(int i = 0; i < M; i++){
        int p = T[i] - 'a';
        int idx = lower_bound(iTable[p].begin(), iTable[p].end(), (lIdx + 1)) - iTable[p].begin();
        if(idx == iTable[p].size()){
            roll += 1;
            idx = 0;
        }

        int v = iTable[p][idx];
        lIdx = v;
    }
    cout << (long long) roll * N + lIdx + 1 << "\n";
}