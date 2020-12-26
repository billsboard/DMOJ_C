#pragma GCC optimize("Ofast") 
#include <stdio.h>

int R[1001], G[1001];
int N, L, t = 0;

int main(){
    scanf("%d %d", &N, &L);
    int p;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &p);
        scanf("%d %d", &R[p], &G[p]);
    }

    for (int i = 1; i <= L; i++)
    {
        t++;
        if(R[i] && (t % (R[i] + G[i])) < R[i])
            t += R[i] - (t % (R[i] + G[i]));
    }
    printf("%d\n", t);
}