#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 222222
typedef long long ll;
typedef struct{
    int a, b;
} pair;
typedef struct _list{
    int val;
    struct _list *next;
} node;
bool isBipartite=1, vis[N], clr[N];
int n, m, x, y;
node *g[N];
pair edge[N];
void push(int u, int v){
    node *ptr=(node *) malloc(sizeof(node));
    ptr->val=v;
    ptr->next=g[u];
    g[u]=ptr;
}
void dfs_vis(int val){
    vis[val]=1;
    for (node *a=g[val]; a; a=a->next){
        if (!vis[a->val]){
            clr[a->val]=!clr[val];
            dfs_vis(a->val);
        }
        else {
            if (clr[a->val]==clr[val])
                isBipartite=0;
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d%d", &x, &y);
        push(x, y);
        push(y, x);
        edge[i].a=x;
        edge[i].b=y;
    }
    dfs_vis(1);
    if (isBipartite){
        printf("YES\n");
        for (int i=0; i<m; i++)
            printf("%d", (clr[edge[i].a]>clr[edge[i].b]));
    }
    else
        printf("NO\n");
}
