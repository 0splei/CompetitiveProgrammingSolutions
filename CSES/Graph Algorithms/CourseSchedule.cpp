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
map <ll, ll> inDegree;
vl graph[(ll) (1e5 + 5)], ans;

void khan() {

    for (ll i = 1; i <= n; i++) {

        for (auto j : graph[i]) inDegree[j]++;

    }

    queue <ll> nodes;

    for (ll i = 1; i <= n; i++) if (inDegree[i] == 0) {ans.pb(i); nodes.push(i);}

    while (!nodes.empty()) {

        ll node = nodes.front();
        nodes.pop();

        for (auto i : graph[node]) {

            inDegree[i]--;

            if (inDegree[i] == 0) {
                
                nodes.push(i);
                ans.pb(i);

            }

        }

    }

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);

    }

    khan();

    if (ans.size() == n) {

        for (auto i : ans) cout << i << " ";
        cout << "\n";

    } else cout << "IMPOSSIBLE\n";

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