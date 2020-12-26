#include <iostream>

using namespace std;

char a[1000000], b[1000000];

int main() {
    cin.getline(a, 1000000, '\n');
    cin.getline(b, 1000000, '\n');
    
    char * c = strstr(a, b);
    if(c == NULL)
        cout << "-1\n";
    else
        cout << c - a << "\n";
}
