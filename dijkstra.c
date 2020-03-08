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
ll n, m, u, v, w, size, dist[N], prev[N];
pair pq[N];
void min_heapify(ll ind){
    if (!ind)
        return;
    ll l=ind*2, r=l+1, lowest=ind;
    if (l<=size&&(pq[l].v<pq[ind].v||pq[l].w<pq[ind].w))
        lowest=l;
    if (r<=size&&(pq[r].v<pq[ind].v||pq[r].w<pq[ind].w))
        lowest=r;
    if (lowest!=ind){
        pair tmp=pq[ind];
        pq[ind]=pq[lowest];
        pq[lowest]=tmp;
        min_heapify(lowest);
    }
}
pair top(void){
    pair min=pq[1];
    pq[1]=pq[size];
    size--;
    min_heapify(1);
    return min;
}
void pushh(ll v, ll w){
    ++size;
    pq[size].v=v;
    pq[size].w=w;
    min_heapify(size/2);
}
void pushg(ll u, ll v, ll w){
    list *ptr=(list *) malloc(sizeof(list));
    ptr->next=g[u];
    ptr->p.v=v;
    ptr->p.w=w;
    g[u]=ptr;
}
void dijkstra(ll s){
    for (ll i=1; i<=n; i++)
        dist[i]=LLONG_MAX;
    dist[s]=0;
    pushh(1, 0);
    while (size){
        pair p=top();
        ll u=p.v;
        for (list *a=g[u]; a; a=a->next){
            pair v=a->p;
            if (dist[u]+v.w<dist[v.v]){
                dist[v.v]=dist[u]+v.w;
                prev[v.v]=u;
                pushh(v.v, w);
            }
        }
    }
}
