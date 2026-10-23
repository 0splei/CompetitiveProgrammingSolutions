#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<LL> vll;

#define pb push_back
#define F first
#define S second

vl graph[5005], invertedGraph[5005], order;
vll edges;
bool seen[5005], reachable[5005];
ll n, m, s, u, v, components[5005], comp = 0;

void dfs (ll node) {

    if (seen[node]) return;

    seen[node] = true;

    for (auto i : graph[node]) dfs(i);

    order.pb(node);

}

void dfs2 (ll node) {

    if (components[node] != -1) return;

    components[node] = comp;

    for (auto i : invertedGraph[node]) dfs2(i);

}

void SOLVE(){

    cin >> n >> m >> s;

    for (ll i = 0; i < m; i++) {

        cin >> u >> v;
        graph[u].pb(v);
        invertedGraph[v].pb(u);
        edges.pb({u, v});

    }

    memset(seen, false, sizeof(seen));
    memset(components, -1, sizeof(components));

    dfs(s);
    memcpy(reachable, seen, sizeof(seen));

    for (ll i = 1; i <= n; i++) {
        if (!seen[i]) dfs(i);
    }

    reverse(order.begin(), order.end());

    for (auto i : order) {

        if (components[i] == -1) {

            dfs2(i);
            comp++;

        }

    }

    bool reachedComp[5005] = {};

    for (ll i = 1; i <= n; i++) {

        if (reachable[i]) {
            reachedComp[components[i]] = true;
        }

    }

    vl inDegree(comp, 0);

    for (ll i = 0; i < m; i++) {

        ll a = components[edges[i].F];
        ll b = components[edges[i].S];

        if (a != b) inDegree[b]++;

    }

    ll ans = 0;

    for (ll i = 0; i < comp; i++) {

        if (!reachedComp[i] && inDegree[i] == 0) ans++;

    }

    cout << ans << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  //cin >> t;
  while(t--){
    SOLVE();
  }
  return 0;
}