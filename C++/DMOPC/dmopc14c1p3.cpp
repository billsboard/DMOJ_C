#include <iostream>

using namespace std;

int sum = 0, stu = 0, N, M, x;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; stu = N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        sum += x;
    }

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> x;
        stu++; sum += x;
        cout << 1.0 * sum / stu << "\n";
    }
}