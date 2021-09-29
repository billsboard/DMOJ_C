#include <iostream>

using namespace std;

int N;

void recurse(int n, char f, char t, char e) {
    if(n == 1) {
        cout << f << t << "\n";
    }
    else {
        recurse(n - 1, f, e, t);
        cout << f << t << "\n";
        recurse(n - 1, e, t, f);
    }
}

int main() {
    cin >> N;
    recurse(N, 'A', 'C', 'B');
}