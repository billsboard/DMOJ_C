#include <iostream>
#include <vector>

using namespace std;

vector<double> stream;
int N, x, y, z;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        stream.push_back(x);
    }

    cin >> x;
    while (x != 77)
    {
        switch (x)
        {
        case 99:
            cin >> y >> z;
            stream.insert(stream.begin() + (y - 1), stream[y - 1] * (z / 100.0));
            stream[y] -= stream[y - 1];
            break;
        
        case 88:
            cin >> y;
            stream[y] += stream[y - 1];
            stream.erase(stream.begin() + (y - 1)); 
            break;
        }
        cin >> x;
    }
    for (double d : stream)
    {
        cout << d << " ";
    }
    cout << "\n";
}