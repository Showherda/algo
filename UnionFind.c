#include <stdio.h>
#define N 222222
typedef long long ll;
typedef struct {ll parent, rank;} pair;
pair set[N];
void makeset(ll val){
	set[val].parent=val;
	set[val].rank=1;
}
ll find(ll val){
	ll tmp=val;
	while (set[tmp].parent!=tmp)
		tmp=set[tmp].parent;
	set[val].parent=tmp;
	return tmp;
}
void merge(ll a, ll b){
	ll roota=find(a), rootb=find(b);
	if (roota!=rootb){
		if (set[roota].rank>set[rootb].rank){
			set[rootb].parent=roota;
			set[roota].rank++;
		}
		else {
			set[roota].parent=rootb;
			set[rootb].rank++;
		}
	}
	
}
