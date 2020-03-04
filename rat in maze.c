#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
int safe(int x, int y, int maze[N][N]) {
    return (x>=0&x<N&&y>=0&&y<N&&maze[x][y]);
}
int solve(int maze[N][N], int x, int y, int sol[N][N]){
    if (x==N-1&&y==N-1){
        sol[x][y]=1;
        return 1;
    }
    if (safe(x, y, maze)){
        sol[x][y]=1;
        if (solve(maze, x+1, y, sol))
            return 1;
        if (solve(maze, x, y+1, sol))
            return 1;
        sol[x][y]=0;
        return 0;
    }
    return 0;
}
void input(int maze[N][N]){
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            scanf("%d", &maze[i][j]);
}
void output(int sol[N][N]){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}
int main(){
    int sol[N][N]={0}, maze[N][N]={{1, 0, 0, 0},
                                    {1, 1, 0, 1},
                                    {0, 1, 0, 0},
                                    {1, 1, 1, 1}};
    solve(maze, 0, 0, sol);
    output(sol);
}
