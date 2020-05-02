#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 9
int safe(int x, int y, int sol[N][N]) {return (x>=1&&x<N&&y>=1&&y<N&&sol[x][y]==-1);}
int solve(int x, int y, int movei, int sol[N][N], int xmove[N], int ymove[N]){
    int nextx, nexty;
    if (movei==64)
        return 1;
    for (int k=1; k<N; k++){
        nextx=x+xmove[k];
        nexty=y+ymove[k];
        if (safe(nextx, nexty, sol)){
            sol[nextx][nexty]=movei;
            if (solve(nextx, nexty, movei+1, sol, xmove, ymove))
                return 1;
            else
                sol[nextx][nexty]=-1;
        }
    }
    return 0;
}
int main() {
    int sol[N][N], xmove[N]={0, 2, 1, -1, -2, -2, -1, 1, 2},
    ymove[N]={0, 1, 2, 2, 1, -1, -2, -2, -1};
    for (int i=1; i<N; i++)
        for (int j=1; j<N; j++)
         sol[i][j]=-1;
    sol[1][1]=0;
    solve(1, 1, 1, sol, xmove, ymove);
    for (int i=1; i<N; i++){
        for (int j=1; j<N; j++)
            printf(" %2d ", sol[i][j]);
        printf("\n");
    }
}
