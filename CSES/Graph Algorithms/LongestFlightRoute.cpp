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

vl graph[(ll) (1e5 + 5)], topo, path;
ll n, m, a, b, seen[(ll) (1e5 + 5)], parent[(ll) (1e5 + 5)];
map <ll, ll> inDegree;

void kahn () {

    queue <ll> q;

    for (ll i = 1; i <= n; i++) if (inDegree[i] == 0) q.push(i);

    while (!q.empty()) {

        ll act = q.front();
        q.pop();

        topo.pb(act);

        for (auto i : graph[act]) {

            inDegree[i]--;

            if (inDegree[i] == 0) q.push(i);

        }

    }

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        inDegree[b]++;

    }

    memset(parent, -1, sizeof(parent));
    memset(seen, -1, sizeof(seen));

    kahn();

    seen[1] = 0;

    for (ll i : topo) {

        if (seen[i] == -1) continue;

        for (ll node : graph[i]) {

            if (seen[node] < seen[i] + 1) {

                seen[node] = seen[i] + 1;
                parent[node] = i;

            }

        }

    }

    if (seen[n] == -1) {

        cout << "IMPOSSIBLE\n";
        return;

    }

    ll act = n;
    cout << seen[n] + 1 << "\n";

    while (act != -1) {

        path.pb(act);
        act = parent[act];

    }

    reverse(path.begin(), path.end());
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