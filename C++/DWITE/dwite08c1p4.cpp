#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string S;
int sum = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (size_t i = 0; i < 5; i++)
    {
        cin >> S;
        int idx; sum = 0;
        if((idx = S.find("IV")) != string::npos){
            S.replace(idx, 2, "");
            sum += 4;
        }
        if((idx = S.find("IX")) != string::npos){
            S.replace(idx, 2, "");
            sum += 9;
        }
        if((idx = S.find("XL")) != string::npos){
            S.replace(idx, 2, "");
           sum += 40;
        }
        if((idx = S.find("XC")) != string::npos){
            S.replace(idx, 2, "");
           sum += 90;
        }
        if((idx = S.find("CD")) != string::npos){
            S.replace(idx, 2, "");
           sum += 400;
        }
        if((idx = S.find("CM")) != string::npos){
            S.replace(idx, 2, "");
           sum += 900;
        }

        for (size_t i = 0; i < S.size(); i++)
        {
            switch (S[i])
            {
            case 'I':
                sum++;
                break;
            case 'V':
                sum += 5;
                break;
            case 'X':
                sum += 10;
                break;
            case 'L':
                sum += 50;
                break;
            case 'C':
                sum += 100;
                break;
            case 'D':
                sum += 500;
                break;
             case 'M':
                sum += 1000;
                break;               
            default:
                break;
            }
        }
        cout << sum << "\n";
    }
    
}
