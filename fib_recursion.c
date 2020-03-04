#include <stdio.h>
typedef long long ll;
ll dp[111];
ll fib(ll f)
{
    ll ans;
    if (!f) ans=0;
    else if (f<3) ans=1;
    else if (dp[f]) ans=dp[f];
    else ans=fib(f-1)+fib(f-2);
    dp[f]=ans;
    return ans;
}
ll main()
{
    ll n, i;
    scanf("%lld", &n);
    for (i=0; i<=n; i++) printf("%3lldth fibonacci number is: %lld\n", i, fib(i));
    return 0;
}
