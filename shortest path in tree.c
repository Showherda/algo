#include <stdio.h>
#include <stdlib.h>
#define N 55555
typedef struct _list{
    int v, w;
    struct _list *next;
} list;
int n, u, v, w, m, height[N*5], first[N], tree[N*20], euler[N*5], ind, vis[N];
list *g[N];
int min(int a, int b) {return a<b?a:b;}
void pushGraph(int u, int v, int w){
    list *ptr=(list *) malloc(sizeof(list));
    ptr->next=g[u];
    g[u]=ptr;
    ptr->v=v;
    ptr->w=w;
}
void build(int tl, int tr, int tv){
    if (tl==tr)
        tree[tv]=height[tl];
    else{
        int tm=(tl+tr)/2;
        build(tl, tm, tv*2);
        build(tm+1, tr, tv*2+1);
        tree[tv]=min(tree[tv*2], tree[tv*2+1]);
    }
}
int query(int tl, int tr, int tv, int l, int r){
    if (tl>r||tr<l)
        return 999999;
    if (tl>=l&&tr<=r)
        return tree[tv];
    int tm=(tl+tr)/2;
    return min(query(tl, tm, tv*2, l, r), query(tm+1, tr, tv*2+1, l, r));
}
void dfs(int h, int u){
    vis[u]=1;
    ind++;
    if (!first[u])
        first[u]=ind;
    euler[ind]=u;
    height[u]=h;
    ind++;
    for (list *a=g[u]; a; a=a->next)
        if (!vis[a->v])
            dfs(h+1, a->v),
            euler[ind]=u;
}
int lca(int u, int v){
    int l=first[u], r=first[v];
    if (l>r){
        int tmp=r;
        r=l;
        l=tmp;
    }
    return query(1, ind, 1, l, r);
}
int main(){
    scanf("%d", &n);
    for (int i=1; i<n; i++)
        scanf("%d%d%d", &u, &v, &w),
        pushGraph(u, v, w),
        pushGraph(v, u, w);
    dfs(1, 0);
    build(1, ind, 1);
    scanf("%d", &m);
    while (m--){
        scanf("%d%d", &u, &v);
        int p=lca(u, v);
        printf("%d\n", height[u]+height[v]-2*height[p]);
    }
}
