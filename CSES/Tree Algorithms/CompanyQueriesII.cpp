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

const ll MAXN = 2e5 + 5;
const ll LOG = 20;

vl graph[MAXN];
ll up[MAXN][LOG], depth[MAXN];

void build (ll root, ll n) {
    
    for (ll i = 1; i <= n; i++) {
        
        depth[i] = 0;

        for (ll j = 0; j < LOG; j++) up[i][j] = 0;

    }

    vl order;
    order.pb(root);

    up[root][0] = 0;
    depth[root] = 0;

    for (ll i = 0; i < order.size(); i++) {

        ll u = order[i];

        for (ll v : graph[u]) {

            if (v == up[u][0]) continue;

            up[v][0] = u;
            depth[v] = depth[u] + 1;
            order.pb(v);

        }

    }

    for (ll j = 1; j < LOG; j++) {

        for (ll i = 1; i <= n; i++) {

            up[i][j] = up[up[i][j - 1]][j - 1];

        }

    }

}

ll kthAncestor(ll u, ll k) {
    
    for (ll j = 0; j < LOG; j++) {
        
        if (k & (1LL << j)) u = up[u][j];
    
    }

    return u;

}

ll LCA (ll u, ll v) {

    if (depth[u] < depth[v]) swap(u, v);

    u = kthAncestor (u, depth[u] - depth[v]);

    if (u == v) return u;

    for (ll j = LOG - 1; j >= 0; j--) {

        if (up[u][j] != up[v][j]) {

            u = up[u][j];
            v = up[v][j];

        }

    }

    return up[u][0];

}

ll dist (ll u, ll v) {

    ll lca = LCA(u, v);

    return depth[u] + depth[v] - 2 * depth[lca];

}

void SOLVE() {

    ll n, q;
    
    cin >> n >> q;

    for (ll i = 1; i <= n; i++) graph[i].clear();

    for (ll i = 2; i <= n; i++) {
    
        ll v;
    
        cin >> v;

        graph[v].pb(i);
    
    }

    build(1, n);

    while (q--) {
    
        ll u, v;
        cin >> u >> v;

        cout << LCA (u, v) << "\n";
    
    }
    
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