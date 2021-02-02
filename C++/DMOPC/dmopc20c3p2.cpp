#include <iostream>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;
const int MAXN = 200001, MAXM = 20;
typedef pair<int, int> pii;

int arr[MAXN][MAXM], N, M, K, cnt = 0;
pii tmp[MAXN];

int main(){
    cin >> N >> M >> K;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (size_t i = 0; i < M - 1; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            tmp[j] = make_pair(arr[j][i], j);
        }

        sort(tmp, tmp + N);
        
        int l = 0, r = 1;
        while (l <= r && r < N)
        {
            int d = tmp[r].first - tmp[l].first;
            if(l == r) r++;
            else if(d == K){
                if(arr[tmp[r].second][i + 1] - arr[tmp[l].second][i + 1] == K) cnt++;
                r++;
            }
            else if(d < K) r++;
            else l++;
        }
    }
    cout << cnt << "\n";
}