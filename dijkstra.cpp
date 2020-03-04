#include <bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
#define N 222222
typedef long long ll;
ll n, m, a, b, w;
void dijkstra(ll s, vector<pair<ll, ll>> adj[], vector<ll>& d, vector<ll>& p) {
    vector<bool> u(N, false);
    d[s]=0;
    for (ll i=1; i<=n; i++) {
        ll v=-1;
        for (ll j=1; j<=n; j++) {
            if (!u[j]&&(v==-1||d[j]))
                v=j;
        }
        if (d[v]==INF)
            break;
        u[v]=true;
        for (auto edge:adj[v]) {
            ll to=edge.first;
            ll len=edge.second;
            if (d[v]+len<d[to])
                d[to]=d[v]+len, p[to]=v;
        }
    }
}
int main() {
    cin >> n >> m;
    vector<ll> b[N], p[N], path[N];
    vector<pair<ll, ll>> adj[N];
    while (m--) {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
    }
    dijkstra(1, adj, d, p);
    for (ll i=n; i!=1; i=p[i])
        path.push_back(i);
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (auto i=path.begin(); i!=path.end(); ++i)
        cout << *i;
}
