#include <iostream>
#include <algorithm>

using namespace std;
const int MAXH = 2 + 1, MAXW = 300 + 1;

int h1, h2, w1, w2, dp[MAXH][MAXW][MAXH][MAXW];
// DP (b1 height)(b1 width) (b2 height)(b2 width)

void recurse(int h1, int w1, int h2, int w2){
    if(h1 == 1 && w1 == 1 && h2 == 1 && w2 == 1) {
        dp[1][1][1][1] = 0;
        return;
    }

    if(dp[h1][w1][h2][w2] != -1) return;

    dp[h1][w1][h2][w2] = 0;
    dp[h2][w2][h1][w1] = 0;

    bool wtf = false;

    // Opt 1 Disc 1
    if(h2 == 2){
        recurse(1, w2, 1, w2);
        if(dp[1][w2][1][w2] == 0){
            wtf = true;
        }
    }
    for (int i = 1; i < w2; i++)
    {
        recurse(h2, i, h2, w2 - i);
        if(dp[h2][i][h2][w2 - i] == 0) wtf = true;
    }

    // Opt 1 Disc 2
    if(h1 == 2){
        recurse(1, w1, 1, w1);
        if(dp[1][w1][1][w1] == 0){
            wtf = true;
        }
    }
    for (int i = 1; i < w1; i++)
    {
        recurse(h1, i, h1, w1 - i);
        if(dp[h1][i][h1][w1 - i] == 0) wtf = true;
    }

    // Opt 2 Cut 1
    if(h1 == 2){
        recurse(1, w1, 1, w2);
        if(dp[1][w1][h2][w2] == 0) wtf = true;
    }
    for (int i = 1; i <= 10; i++)
    {
        if(w1 - i <= 0) break;
        recurse(h1, w1 - i, h2, w2);
        if(dp[h1][w1 - i][h2][w2] == 0) wtf = true;
    }

    // Opt 2 Cut 2
    if(h2 == 2){
        recurse(1, w2, 1, w1);
        if(dp[1][w2][h1][w1] == 0) wtf = true;
    }
    for (int i = 1; i <= 10; i++)
    {
        if(w2 - i <= 0) break;
        recurse(h2, w2 - i, h1, w1);
        if(dp[h2][w2 - i][h1][w1] == 0) wtf = true;
    }


    dp[h1][w1][h2][w2] = wtf;
    dp[h2][w2][h1][w1] = wtf;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> h1 >> w1 >> h2 >> w2;

    fill(&dp[0][0][0][0], &dp[0][0][0][0] + sizeof(dp) / sizeof(dp[0][0][0][0]), -1);

    recurse(h1, w1, h2, w2);
    if(dp[h1][w1][h2][w2]) cout << "W\n";
    else cout << "L\n";
}