#include <iostream>
#include <unordered_set>

using namespace std;

int N, x;
unordered_set<int> st;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        st.insert(x);
    }

    cout << (st.size() == N ? "YES" : "NO") << "\n";   
}