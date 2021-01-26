#include <iostream>
#include <stack>

using namespace std;
const int MAXN = 10000;

char arr[MAXN];
int N;

void increment(){
    int idx = 0;
    while (true)
    {
        char c = arr[idx];
        if(c == 'z'){
            arr[idx] = 'a';
            idx++;
        }
        else{
            arr[idx] = max(arr[idx] + 1, (int) 'a');
            break;
        }
    }
}

void outputStr(){
    stack<char> stk;
    for (size_t i = 0; i < MAXN; i++)
    {
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            stk.push(arr[i]);
        }
        else{
            break;
        }
    }

    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    cout << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr[0] = 'a';
    for (size_t i = 0; i < N; i++)
    {
        outputStr();
        increment();
    }
    cout << "\n";
}