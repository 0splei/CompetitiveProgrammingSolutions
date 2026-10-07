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

ll n, m, a, b, mod = 1e9 + 7, ways[(ll) (1e5 + 5)];
vl graph[(ll) (1e5 + 5)], parents[(ll) (1e5 + 5)], topo;
map <ll, ll> inDegree;

void kahn () {

    queue <ll> q;
    for (ll i = 1; i <= n; i++) if (inDegree[i] == 0) q.push(i);

    while (!q.empty()) {

        ll node = q.front();
        q.pop();

        topo.pb(node);

        for (auto i : graph[node]) {

            inDegree[i]--;

            if (inDegree[i] == 0) q.push(i);

        }

    }

}

void bfs () {

    for (auto i : topo) {

        ll node = i, sum = 0;

        for (auto i : parents[node]) {
            
            sum += ways[i] % mod;
            sum %= mod;

        }

        if (node == 1) sum = 1, ways[node] = 1;
        
        if (ways[node] < sum) {
            
            ways[node] = sum % mod;
            ways[node] %= mod;
            
        }

    }

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        parents[b].pb(a);
        inDegree[b]++;

    }

    memset(ways, 0, sizeof(ways));
    kahn();
    bfs();

    cout << ways[n] << "\n";

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