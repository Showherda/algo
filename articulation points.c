#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 222222
typedef long long ll;
typedef struct _list{
    int val;
    struct _list *next;
} node;
node *g[N];
bool vis[N], isArt[N];
int low[N], time[N], timer;
int min(int a, int b){
    return a<b?a:b;
}
void push(int u, int v){
    node *ptr=(node *) malloc(sizeof(node));
    ptr->val=v;
    ptr->next=g[u];
    g[u]=ptr;
}
void dfs_vis(int val, int p){
    vis[val]=true;
    time[val]=low[val]=++timer;
    int children=0;
    for (node *a=g[val]; a; a=a->next){
        int to=a->val;
        if (to==p)
            continue;
        if (!vis[to]){
            dfs_vis(to, val);
            low[val]=min(low[val], low[to]);
            if (low[to]>=time[val]&&p)
                isArt[val]=true;
            ++children;
            }
        else
            low[val]=min(low[val], low[to]);
    }
    if (!p&&children>1)
        isArt[val]=true;
}
void findArtPoints(){
    for (int i=1; i<=9; i++)
        if (!vis[i])
            dfs_vis(i, 0);
}
int main()
{
    push(1, 2);
    push(2, 1);
    push(2, 3);
    push(3, 2);
    push(1, 3);
    push(3, 1);
    push(3, 4);
    push(4, 3);
    push(4, 5);
    push(5, 4);
    push(3, 6);
    push(6, 3);
    push(6, 7);
    push(7, 6);
    push(7, 8);
    push(8, 7);
    push(8, 9);
    push(9, 8);
    push(9, 6);
    push(6, 9);
    findArtPoints();
    for (int i=1; i<=9; i++)
        printf("%d %d\n", i, isArt[i]);
}
