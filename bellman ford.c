#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 222222
typedef long long ll;
typedef struct {ll v, w;} pair;
typedef struct _list{
    pair p;
    struct _list *next;
} list;
list *g[N];
ll n, m, u, v, w, dist[N], prev[N], negcyc;
void pushg(ll u, ll v, ll w){
    list *ptr=(list *) malloc(sizeof(list));
    ptr->next=g[u];
    ptr->p.v=v;
    ptr->p.w=w;
    g[u]=ptr;
}
void init(void){
    for (ll i=1; i<=n; i++)
        dist[i]=LLONG_MAX;
}
void BFrelax(void){
    init();
    for (ll i=1; i<n; i++)
        for (ll j=1; j<=n; j++)
            for (list *a=g[j]; a; a=a->next){
                u=j; v=a->p.v; w=a->p.w;
                if (dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    prev[v]=u;
                }
            }
}
void BFcheck(void){
    for (ll i=1; i<n; i++)
        for (ll j=1; j<=n; j++)
            for (list *a=g[j]; a; a=a->next){
                u=j; v=a->p.v; w=a->p.w;
                if (dist[u]+w<dist[v]){
                    dist[v]=LLONG_MIN;
                    negcyc=1;
                }
            }
}
