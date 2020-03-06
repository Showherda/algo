#include <stdio.h>
#include <stdlib.h>
#define N 222222
typedef long long ll;
typedef struct {ll parent, rank;} p;
typedef struct {ll u, v;} pp;
typedef struct {ll u, v, w;} ppp;
p vertex[N];
pp mst[N];
ppp edge[N];
ll n, m, ind;
int comp(const void *a, const void *b){
    ppp aa=*(const ppp *)a, bb=*(const ppp *)b;
	return (aa.w<bb.w?-1:(aa.w>bb.w?1:0));
}
void makeset(ll val){
	vertex[val].parent=val;
	vertex[val].rank=1;
}
ll find(ll val){
	ll tmp=val;
	while (vertex[tmp].parent!=tmp)
		tmp=vertex[tmp].parent;
	vertex[val].parent=tmp;
	return tmp;
}
void merge(ll a, ll b){
	ll roota=find(a), rootb=find(b);
	if (roota!=rootb){
		if (vertex[roota].rank>vertex[rootb].rank){
			vertex[rootb].parent=roota;
			vertex[roota].rank++;
		}
		else {
			vertex[roota].parent=rootb;
			vertex[rootb].rank++;
		}
	}
}
void kruskalMST(void){
    for (ll i=1; i<=n; i++)
        makeset(i);
    qsort(edge, m, sizeof(ppp), comp);
    for (ll i=0; i<m; i++)
        if (find(edge[i].u)!=find(edge[i].v)){
            mst[ind].u=edge[i].u, mst[ind].v=edge[i].v;
            ind++;
            merge(edge[i].u, edge[i].v);
        }
}
