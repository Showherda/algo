#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N 222222
typedef long long ll;
typedef struct {ll v, w;} pair;
typedef struct _list{
    pair p;
    struct _list *next;
} list;
bool taken[N];
list *g[N];
ll n, m, u, v, w, size, mstCost;
pair pq[N];
void min_heapify(ll ind){
    ll l=ind*2, r=l+1, lowest=ind;
    if (l<=size&&(pq[l].v<pq[lowest].v||pq[l].w<pq[lowest].w))
        lowest=l;
    if (r<=size&&(pq[r].v<pq[lowest].v||pq[r].w<pq[lowest].w))
        lowest=r;
    if (lowest!=ind){
        pair tmp=pq[ind];
        pq[ind]=pq[lowest];
        pq[lowest]=tmp;
        min_heapify(lowest);
    }
}
void build_min_heap(void){
    for (ll i=size/2; i; i--)
        min_heapify(i);
}
pair extract_min(void){
    pair min=pq[1];
    pq[1]=pq[size];
    --size;
    min_heapify(1);
    return min;
}
void pushh(ll v, ll w){
    ++size;
    pq[size].v=v;
    pq[size].w=w;
    min_heapify(size);
}
void process(ll vrtx){
    taken[vrtx]=1;
    for (list *a=g[vrtx]; a; a=a->next)
        if (!taken[a->p.v])
            pushh(a->p.v, a->p.w);
}
void pushg(ll u, ll v, ll w){
    list *ptr=(list *) malloc(sizeof(list));
    ptr->next=g[u];
    ptr->p.v=v;
    ptr->p.w=w;
    g[u]=ptr;
}
void primMST(void){
    process(1);
    while (size){
        pair front=extract_min();
        u=front.v, w=front.w;
        if (!taken[u]){
            mstCost+=w;
            process(u);
        }
    }
}
