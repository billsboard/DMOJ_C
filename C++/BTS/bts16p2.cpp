#include <iostream>
#include <string>

using namespace std;

int arr[2], N, t, e;
string s;

int index(string s){
    return s == "true";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr[0] = -1;
    arr[1] = -1;

    for (size_t i = 0; i < N; i++)
    {
        cin >> t;
        if(t == 1){
            cin >> s;
            e = index(s);

            if(arr[e] == -1){
                cout << "true\n";
                arr[e] = arr[!e] + 1;
            }
            else {
                cout << "false\n";
            }
        }
        else if(t == 2){
            cin >> s;
            e = index(s);
            if(arr[e] == -1){
                cout << "false\n";
            }
            else {
                if(arr[!e] > arr[e]) arr[!e]--;
                arr[e] = -1;
                cout << "true\n";
            }
        }
        else if(t == 3){
            cin >> s;
            e = index(s);
            cout << arr[e] << "\n";
        }
        else {
            if(arr[0] != -1) cout << "false ";
            if(arr[1] != -1) cout << "true";
            cout << "\n";
        }
    }
}