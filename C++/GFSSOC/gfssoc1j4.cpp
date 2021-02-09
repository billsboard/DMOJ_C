#include <iostream>

using namespace std;

char arr[9];
bool t = false, g = false;

/*
0 1 2
3 4 5
6 7 8
*/

void checkWin(int a, int b, int c){
    if(arr[a] == arr[b] && arr[b] == arr[c]){
        if(arr[a] == 'X') t = 1;
        else g = 1;
    };
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (size_t i = 0; i < 9; i++)
    {
        cin >> arr[i];
    }

    checkWin(0, 1, 2);
    checkWin(3, 4, 5);
    checkWin(6, 7, 8);
    checkWin(0, 3, 6);
    checkWin(1, 4, 7);
    checkWin(2, 5, 8);
    checkWin(0, 4, 8);
    checkWin(2, 4, 6);

    if(t && g){
        cout << "Error, redo";
    }
    else if(t){
        cout << "Timothy";
    }
    else if(g){
        cout << "Griffy";
    }
    else{
        cout << "Tie";
    }
    cout << "\n";
}