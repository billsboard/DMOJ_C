#include <iostream>

using namespace std;

char freq['z' + 1], c;
int N, single = 0, spt = 0, cnt = 1;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> c;
        freq[c]++;
    }

    for (size_t i = 'a'; i <= 'z'; i++)
    {
        if(freq[i] & 1) single++;
        spt += (freq[i] / 2);
    }

    cnt += single - 1;
    if(cnt == 0) cnt++;
    cout << cnt << "\n";
}