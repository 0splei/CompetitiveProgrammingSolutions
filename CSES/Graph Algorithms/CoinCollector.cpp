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

ll n, m, k, a, b, component[(ll) (1e5 + 5)];
vl graph[(ll) (1e5 + 5)], invertedGraph[(ll) (1e5 + 5)], values, order;
bool seen[(ll) (1e5 + 5)];

void dfs (ll node) {

    if (seen[node] == true) return;

    seen[node] = true;

    for (auto i : graph[node]) dfs(i);

    order.pb(node);

}

ll dfs2 (ll node, ll comp) {

    if (component[node] != -1) return 0;

    component[node] = comp;
    ll sum = 0;

    for (auto i : invertedGraph[node]) sum += dfs2(i, comp);

    return sum + values[node];

}

void SOLVE(){

    cin >> n >> m;
    values.pb(0);

    for (ll i = 0; i < n; i++) {

        cin >> k;
        values.pb(k);

    }

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        invertedGraph[b].pb(a);

    }

    memset(seen, false, sizeof(seen));

    for (ll i = 1; i <= n; i++) {

        if (!seen[i]) dfs(i);

    }

    reverse(order.begin(), order.end());

    memset(component, -1, sizeof(component));

    ll comp = 0;
    vl coinSum;

    for (auto i : order) {

        if (component[i] == -1) {

            coinSum.pb(dfs2(i, comp));
            comp++;

        }

    }

    vector<vl> dag(comp);
    vl indegree(comp, 0);

    for (ll i = 1; i <= n; i++) {

        for (auto j : graph[i]) {

            ll u = component[i];
            ll v = component[j];

            if (u != v) {

                dag[u].pb(v);
                indegree[v]++;

            }

        }

    }

    vl dp = coinSum;
    queue<ll> q;

    for (ll i = 0; i < comp; i++) {

        if (indegree[i] == 0) q.push(i);

    }

    ll ans = 0;

    while (!q.empty()) {

        ll u = q.front();
        q.pop();

        ans = max(ans, dp[u]);

        for (auto v : dag[u]) {

            dp[v] = max(dp[v], dp[u] + coinSum[v]);

            indegree[v]--;

            if (indegree[v] == 0) q.push(v);

        }

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