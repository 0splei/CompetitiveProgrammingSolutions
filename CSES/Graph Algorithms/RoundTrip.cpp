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

const ll MAXN = 1e5 + 5;
ll n, m, a, b, parent[MAXN], cycleStart = -1, cycleEnd = -1;
vl graph[MAXN];
bool seen[MAXN];

bool dfs (ll node, ll comes) {

    seen[node] = true;
    parent[node] = comes;

    for (ll i : graph[node]) {

        if (comes == i) continue;

        if (seen[i] == true) {

            cycleStart = i;
            cycleEnd = node;

            return true;

        }

        if (dfs(i, node) == true) return true;

    }

    return false;

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);

    }

    memset(seen, false, sizeof(seen));

    for (ll i = 1; i <= n; i++) {

        if (seen[i] == false) {

            if (dfs(i, -1) == true) break;

        }

    }

    if (cycleStart == -1) {

        cout << "IMPOSSIBLE\n";
        return;

    }

    vl path;
    ll act = cycleEnd;
    path.pb(cycleStart);

    while (act != cycleStart) {

        path.pb(act);
        act = parent[act];

    }

    path.pb(act);

    cout << path.size() << "\n";
    for (auto i : path) cout << i << " ";
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