#include <iostream>
#include <bitset>
#include <set>
#include <vector>

using namespace std;
const int MAXN = 20;

int N, M, mx;
string A[MAXN], B[MAXN];
vector<int> st;

void recurse(){
    if(st.size() >= M) return;
    else{
        if(st.size() > 0){
            string s = "", t = "";
            for(int i : st){
                s.append(A[i]); t.append(B[i]);
            }
            if(s == t){
                cout << st.size() << "\n";
                for(int i : st) cout << i + 1 << "\n";
                exit(0);
            }
        }

        for (size_t i = 0; i < N; i++)
        {
            st.push_back(i);
            recurse();
            st.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    
    recurse();

    cout << "No solution.\n";
}