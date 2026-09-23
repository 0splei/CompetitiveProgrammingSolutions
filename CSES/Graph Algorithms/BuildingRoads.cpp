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

ll n, m, a, b;
vl graph[(ll) (1e5 + 5)];
vll ans;
bool seen[(ll) (1e5 + 5)];

void dfs (ll node) {

    if (seen[node] == true) return;

    seen[node] = true;

    for (auto i : graph[node]) dfs(i);

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);

    }

    memset(seen, false, sizeof (seen));
    dfs(1);

    for (ll i = 2; i <= n; i++) {

        if (seen[i] != true) {

            ans.pb({i - 1, i});
            dfs(i);

        }

    }

    cout << ans.size() << "\n";
    for (ll i = 0; i < ans.size(); i++) cout << ans[i].F << " " << ans[i].S << "\n";

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