#include <stack>
#include <iostream>
#include <string>

using namespace std;

string s;
int N, T = 5;

char invBrack(char c){
    if(c == '(') return ')';
    else if(c == ')') return '(';
    else if(c == '[') return ']';
    else if(c == ']') return '[';
    else if(c == '{') return '}';
    else if(c == '}') return '{';
    else return 'a';
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    while (T--)
    {
        cin >> s;
        N = s.size();
        stack<char> stk;
        for (size_t i = 0; i < N; i++)
        {
            char c = s[i];
            char cnv = invBrack(c);

            if(cnv == 'a') continue;
            
            if(c == '{' || c == '(' || c == '['){
                stk.push(c);
            }
            else {
                if(stk.empty() || stk.top() != cnv){
                    cout << "not balanced\n";
                    goto cont;
                }

                stk.pop();
            }
        }

        cout << (stk.empty() ? "balanced" : "not balanced") << "\n";

        cont:;
    }
}
