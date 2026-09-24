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

ll n, m, a, b, ans[(ll) (2 * 1e5) + 5];
vl graph[(ll) (2 * 1e5) + 5];
bool seen[(ll) (2 * 1e5) + 5], can = true;

void dfs (ll node, ll color) {

    if (seen[node] == true) {
        
        if (ans[node] != color) can = false;
        return;
    
    }

    seen[node] = true;
    ans[node] = color;

    for (auto i : graph[node]) {
        
        if (color == 1) dfs(i, 2);
        else dfs(i, 1);
    
    }

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);

    }

    memset(seen, false, sizeof(seen));

    for (ll i = 0; i < n; i++) {

        if (seen[i] == false) {

            dfs(i, 1);

        }

    }

    if (can == false) {

        cout << "IMPOSSIBLE\n";
        return;

    }

    for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";

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