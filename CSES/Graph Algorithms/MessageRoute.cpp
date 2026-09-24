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

ll n, m, a, b, parent[(ll) (1e5 + 5)];
vl graph[(ll) (1e5 + 5)], path;
bool seen[(ll) (1e5 + 5)];

bool bfs (ll start) {

    queue <ll> node;

    node.push(start);
    
    while (!node.empty()) {
        
        ll act = node.front();
        node.pop();
        
        for (auto i : graph[act]) {
            
            if (seen[i] == true) continue;
            
            seen[i] = true;
            node.push(i);
            parent[i] = act;
        
        }

    }

    return seen[n];
    
}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);

    }

    memset(seen, false, sizeof(seen));
    memset(parent, -1, sizeof(parent));

    if (bfs(1) == false) {

        cout << "IMPOSSIBLE\n";
        return;

    }

    parent[1] = -1;
    ll pos = n;

    while (pos != 1) {

        path.pb(pos);
        pos = parent[pos];

    }

    path.pb(1);
    cout << path.size() << "\n";

    for (ll i = path.size() - 1; i >= 0; i--) {

        cout << path[i] << " ";

    }

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