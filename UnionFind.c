#include <stdio.h>
#define N 222222
typedef long long ll;
typedef struct {ll parent, rank;} pair;
pair set[N];
void makeset(ll val){
	set[val].parent=0;
	set[val].rank=1;
}
ll find(ll val){
	ll tmp=val;
	while (set[tmp].parent)
		tmp=set[tmp].parent;
	if (tmp)
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
int main() {
	for (ll i=1; i<=10; i++)
		makeset(i);
	for (ll i=1; i<10; i++)
		merge(i, i+1);
	for (ll i=1; i<=10; i++)
		printf("%lld\n", find(i));
	return 0;
}
