#include <iostream>

using namespace std;

char arr[10];
int N, x;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (size_t i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        cout << arr[x];
    }
    cout << "\n";
}