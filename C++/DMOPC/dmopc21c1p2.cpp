#include <iostream>
#include <deque>

using namespace std;
const int MAXN = 2 * 1e3 + 1;

deque<int> s1, s2, res;
int N, a, x, y, z;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> a;
        s1.push_back(a);
    }
    
    while (!s1.empty())
    {
        x = s1.front();
        int i = 0;
        while (i < s2.size() && s2[i] < x)
        {
            i++;
        }

        if(i == 0) {
            res.push_back(1);
        }
        else {
            res.push_back(-i);
            res.push_back(i);
        }
        s1.pop_front();
        s2.insert(s2.begin() + i, x);
    }
    
    res.push_back(-N);
    cout << res.size() << "\n";
    for(int i : res) {
        cout << i << "\n";
    }
}