#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 222222
typedef long long ll;
typedef struct _list {
    ll val;
    struct _list *next;
} list;
typedef struct {
    ll d, p, v;
} vertex;
typedef struct _pair {
    ll u, v, w;
    struct _pair *next;
} pair;
list *g[N];
ll n, m, a, b, w, size;
pair *edge[N];
vertex heap[N], arr[N];
void pushg(ll u, ll v){
    list *ptr=(list *) malloc(sizeof(list));
    ptr->val=v;
    ptr->next=g[u];
    g[u]=ptr;
}
ll hash_fun(ll u, ll v){
    return ((u*17LL+v*23LL)%N);
}
void pushh(ll u, ll v, ll w){
    ll ind=hash_fun(u, v);
    pair *ptr=(pair *) malloc(sizeof(pair));
    ptr->next=edge[ind];
    ptr->u=u;
    ptr->v=v;
    ptr->w=w;
    edge[ind]=ptr;
}
void min_heapify(ll ind){
    ll l=ind*2, r=l+1, lowest=ind;
    if (l<=size && heap[l].d<heap[ind].d)
        lowest=l;
    if (r<=size && heap[r].d<heap[ind].d)
        lowest=r;
    if (lowest!=ind) {
        vertex tmp=heap[lowest];
        heap[lowest]=heap[ind];
        heap[ind]=tmp;
        min_heapify(lowest);
    }
}
void build_min_heap(void){
    for (ll i = size/2; i>=1; i--)
        min_heapify(i);
}
vertex extract_min(void){
    vertex min=heap[1];
    heap[1]=heap[size];
    size--;
    min_heapify(1);
    return min;
}
void relax(ll u, ll v){
    ll ind=hash_fun(u, v), w;
    for (pair *a=edge[ind]; a; a=a->next)
        if (a->u==u&&a->v==v){
            w=a->w;
            break;
        }
    if (heap[v].d>heap[u].d+w)
        heap[v].d=heap[u].d+w, heap[v].p=u,
        arr[v].d=heap[u].d+w, arr[v].p=u;
}
void dijkstra(ll s){
    while (size){
        vertex u=extract_min();
        for (list *a=g[u.v]; a; a=a->next)
            relax(u.v, a->val);
    }
}
int main(){
    scanf("%I64d%I64d", &n, &m);
    while (m--){
        scanf("%I64d%I64d%I64d", &a, &b, &w);
        pushg(a, b);
        pushg(b, a);
        pushh(a, b, w);
        pushh(b, a, w);
    }
    for (int i=1; i<=n; i++){
        heap[++size].v=i;
        heap[size].d=LLONG_MAX;
        heap[size].p=-1;
        arr[size].v=i;
        arr[size].p=-1;
        arr[size].d=LLONG_MAX;
    }
    build_min_heap();
    dijkstra(1);
    for (ll i=1; i<=n; i++)
        printf("%I64d %I64d\n", i, arr[i].p);
}
