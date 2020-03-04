#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull dp[111];
ull fib(ull f)
{
    ull ans;
    if (dp[f]) ans=dp[f];
    else if (!f) ans=0;
    else if (f<3) ans=1;
    else ans=fib(f-1)+fib(f-2);
    dp[f]=ans;
    return ans;
}
int main()
{
    ull n, i;
    cin >> n;
    for (i=0; i<=n; i++) printf("%3lluth fibonacci number is %llu\n", i, fib(i));
    return 0;
}
