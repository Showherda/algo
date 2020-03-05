#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 222222
typedef long long ll;
typedef struct _list{
    ll val;
    struct _list *next;
} list;
bool vis[N];
list *g[N], *head, *tail;
ll num[N], low[N], count, numSCC;
ll min(ll a, ll b){
    return a<b?a:b;
}
void pushg(ll u, ll v){
    list *ptr=(list *) malloc(sizeof(list));
    ptr->val=v;
    ptr->next=g[u];
    g[u]=ptr;
}
void pushs(ll val){
    list *ptr=(list *) malloc(sizeof(list)), *tmp=head;
    ptr->val=val;
    ptr->next=NULL;
    if (!tmp){
        tail=head=ptr;
        return;
    }
    while (tmp->next)
        tmp=tmp->next;
    tmp->next=ptr;
    tail=ptr;
}
ll pops(void){
    list *ptr=head, *tmp=head;
    ll val=tail->val;
    if (head==tail){
        free(head);
        tail=NULL;
        return val;
    }
    ptr=ptr->next;
    while (ptr->next){
        tmp=tmp->next;
        ptr=ptr->next;
    }
    tail=tmp;
    tmp->next=NULL;
    free(ptr);
    return val;
}
void tarjanSCC(ll u){
    low[u]=num[u]=++count;
    vis[u]=true;
    pushs(u);
    for (list *a=g[u]; a; a=a->next){
        if (num[a->val]==-1)
            tarjanSCC(a->val);
        if (vis[a->val])
            low[u]=min(low[u], low[a->val]);
    }
    if (low[u]==num[u]){
        ++numSCC;
        while (true){
            ll v=pops();
            vis[v]=0;
            printf(" %I64d", v);
            if (u==v)
                break;
        }
        printf("\n");
    }
}
int main(){
    memset(num, -1, sizeof(num));
    pushg(0, 1);
    pushg(1, 3);
    pushg(3, 2);
    pushg(2, 1);
    pushg(3, 4);
    pushg(4, 5);
    pushg(5, 7);
    pushg(7, 6);
    pushg(6, 4);
    for (ll i=0; i<8; i++)
        if (num[i]==-1)
            tarjanSCC(i);
    printf("numSCC = %I64d\n", numSCC);
}
