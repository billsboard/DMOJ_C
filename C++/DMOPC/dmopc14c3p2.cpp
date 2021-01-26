#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAXN = 1000;

int N, wa = 0, ir = 0;
string arr[MAXN], s;
vector<int> was;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> s;
        if(s == "TLE") arr[i] = "WA";
        if(s == "IR"){
            if(ir < 10){
                arr[i] = "AC";
            }
            else if(ir < 20){
                arr[i] = "WA";
            }
            else arr[i] = "IR";
            ir++;
        }
        if(s == "WA"){
            wa++;
            was.push_back(i);
            arr[i] = "WA";
        }
        if(s == "AC")
            arr[i] = "AC";
    }

    double cnt = 0.3 * wa;
    cnt = (int) cnt;
    for (size_t i = 0; i < cnt; i++)
    {
        arr[was[i]] = "AC";
    }

    for (size_t i = 0; i < N; i++)
    {
        cout << arr[i] << "\n";
    }
}