#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<string> words1, words2;
int A, B, cnt = 0;
string S;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    for (size_t i = 0; i < A; i++)
    {
        cin >> S;
        words1.insert(S);
    }

    for (size_t i = 0; i < B; i++)
    {
        cin >> S;
        if(words2.find(S) == words2.end()){
            words2.insert(S);
            cnt += words1.find(S) != words1.end();
        }
    }

    cout << cnt << "\n";
}