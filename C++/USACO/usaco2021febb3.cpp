#include <iostream>
#include <string>

using namespace std;
const int inf = 1 << 30;

struct pt {
    double x, y;
};

int N, cx, cy, px = 0, py = 0, sum = 0, L;
char c;
string s;
pt pmx, pmn;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    while (N--)
    {
        cx = 0; cy = 0; px = 0; py = 0, sum = 0;
        cin >> s;
        L = s.size();
        for (size_t i = 0; i < L; i++)
        {
            c = s[i];
            if(c == 'N'){
                cy++;
                
            }
            else if(c == 'S'){
                cy--;
            }
            else if(c == 'E'){
                cx++;
            }
            else if(c == 'W'){
                cx--;
            }

            sum += (cx - px) * (cy + py);
            px = cx;
            py = cy;
        }

        if(sum < 0) cout << "CCW";
        else cout << "CW";
        cout << "\n";
    }
}