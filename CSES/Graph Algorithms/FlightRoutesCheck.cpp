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

vl graph[(ll) (1e5 + 5)], invertedGraph[(ll) (1e5 + 5)], order;
bool seen[(ll) (1e5 + 5)];
ll n, m, a, b;

void dfs (ll node) {

	if (seen[node] == true) return;

	seen[node] = true;

	for (auto i : graph[node]) dfs(i);

	order.pb(node);

}

void dfsInverted (ll node) {

	if (seen[node] == true) return;

	seen[node] = true;

	for (auto i : invertedGraph[node]) dfsInverted(i);

	order.pb(node);

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
		invertedGraph[b].pb(a);
    
	}

	memset(seen, false, sizeof(seen));
	dfs(1);

	for (ll i = 1; i <= n; i++) {

		if (seen[i] == false) {

			cout << "NO\n";
			cout << "1 " << i << "\n";
			return;

		}

	}

	memset(seen, false, sizeof(seen));

	dfsInverted(order[order.size() - 1]);

	for (ll i = 1; i <= n; i++) {

		if (seen[i] == false) {

			cout << "NO\n";
			cout << i << " 1\n";
			return;

		}

	}

	cout << "YES\n";

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