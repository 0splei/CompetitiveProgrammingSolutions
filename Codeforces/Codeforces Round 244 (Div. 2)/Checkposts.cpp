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

vl values, graph[(ll) (1e5 + 5)], invertedGraph[(ll) (1e5 + 5)], order;
ll n, m, x, a, b, component[(ll) (1e5 + 5)], ans = 1, comp = 0, mod = 1e9 + 7;
map <ll, LL> options;
bool seen[(ll) (1e5 + 5)];

void dfs (ll node) {

    if (seen[node] == true) return;

    seen[node] = true;

    for (auto i : graph[node]) dfs(i);

    order.pb(node);

}

void dfs2 (ll node) {

    if (component[node] != -1) return;

    component[node] = comp;
    
    if (options[comp].F == -1 || values[node] < options[comp].F) options[comp] = {values[node], 1};
    else if (values[node] == options[comp].F) options[comp].S++;

    for (auto i : invertedGraph[node]) dfs2(i);

}

void SOLVE() {

    cin >> n;
    values.pb(0);

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    cin >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        invertedGraph[b].pb(a);

    }

    memset(seen, false, sizeof (seen));
    memset(component, -1, sizeof(component));

    for (ll i = 1; i <= n; i++) if (!seen[i]) dfs(i);
    reverse(order.begin(), order.end());

    for (auto i : order) {

        if (component[i] == -1) {

            options[comp] = {-1, 0};
            dfs2(i);
            comp++;

        }

    }

    ll total = 0;

    for (auto i : options) {

        total = total + i.S.F;
        ans = (ans * i.S.S) % mod;

    }

    cout << total << " " << ans << "\n";

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