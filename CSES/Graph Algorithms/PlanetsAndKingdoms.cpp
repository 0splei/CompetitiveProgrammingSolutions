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

ll n, m, a, b, component[(ll) (1e5 + 5)], comp = 1;
vl graph[(ll) (1e5 + 5)], invertedGraph[(ll) (1e5 + 5)], order;
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

    for (auto i : invertedGraph[node]) dfs2(i);

}   

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        invertedGraph[b].pb(a);

    }

    if (n == 1) {

        cout << "1\n1";
        return;
        
    }

    memset(seen, false, sizeof(seen));
    memset(component, -1, sizeof(component));

    for (ll i = 1; i < n; i++) if (seen[i] == false) dfs(i);
    reverse(order.begin(), order.end());

    for (auto i : order) {

        if (component[i] == -1) {
            
            dfs2(i);
            comp++;

        }

    }

    cout << comp - 1 << "\n";
    for (ll i = 1; i <= n; i++) cout << component[i] << " ";

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