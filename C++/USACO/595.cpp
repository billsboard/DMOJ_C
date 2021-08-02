#include <iostream>
#include <fstream>

using namespace std;
const int MAXN = 50001;
typedef long long ll;

ll arr[MAXN], psa[MAXN];
int N;
int fidx[7], lidx[7];

int main(){
    ofstream fout;
    ifstream fin;

    fin.open("div7.in");
    fout.open("div7.out");

    fin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        fin >> arr[i];
        psa[i] = arr[i] + psa[i - 1];
    }

    for (size_t i = 1; i <= N; i++)
    {
        psa[i] %= 7;
        if(fidx[psa[i]] == 0) fidx[psa[i]] = i;
        lidx[psa[i]] = i;
    }

    int mx = 0;
    for (size_t i = 0; i <= 6; i++)
    {
        if(lidx[i] == 0 || fidx[i] == 0) continue;
        mx = max(mx, lidx[i] - fidx[i]);
    }
    fout << mx << "\n";
}