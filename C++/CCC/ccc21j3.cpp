#include <iostream>

using namespace std;
int a, c, b, dir = 0, pd = 0;


int readDigit(int x){
    int ret = 0;
    char c;
    for (size_t i = 0; i < x; i++)
    {
        cin >> c;
        ret = (10 * ret) + (c - '0');
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        a = readDigit(1); c = readDigit(1); b = readDigit(3);
        if(a == 9 && c == 9 && b == 999) break;

        int s = a + c;
        
        if(s == 0) dir = pd;
        else if(s & 1) dir = 1;
        else dir = -1;

        cout << (dir == 1 ? "left" : "right") << " ";
        cout << b << "\n";
        pd = dir;
    }   
}