#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 555555
typedef long long ll;
ll tc, n, inp[N], tree[2222222], ans;
ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}
ll sum(ll a, ll b) {return a+b;}
void build(ll tv, ll tl, ll tr)
{
    if (tl==tr) tree[tv]=inp[tl];
    else
    {
        ll tm=(tl+tr)/2;
        build(tv*2, tl, tm);
        build(tv*2+1, tm+1, tr);
        tree[tv]=min(tree[tv*2], tree[tv*2+1]);
    }
}
ll query(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l>r) return LLONG_MAX;
    if (l==tl&&r==tr) return tree[v];
    ll tm=(tl+tr)/2;
    return min(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(ll v, ll tl, ll tr, ll pos, ll new_val)
{
    if (tl==tr) tree[v]=new_val;
    else
    {
        ll tm=(tr+tl)/2;
        if (pos<=tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2+1, tm+1, tr, pos, new_val);
        tree[v]=min(tree[v*2],tree[v*2+1]);
    }
}
int main()
{

}
