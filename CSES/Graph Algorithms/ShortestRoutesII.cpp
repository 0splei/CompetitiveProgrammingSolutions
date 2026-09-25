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

const ll INF = 4e18;

void SOLVE(){

    ll n, m, q, a, b, c, dist[505][505];

    cin >> n >> m >> q;

    for (ll i = 1; i <= n; i++) {

        for (ll j = 1; j <= n; j++) {
        
            dist[i][j] = (i == j ? 0 : INF);
        
        }
    
    }

    for (ll i = 0; i < m; i++) {

        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);

    }

    for (ll k = 1; k <= n; k++) {

        for (ll i = 1; i <= n; i++) {

            for (ll j = 1; j <= n; j++) {

                if (dist[i][k] == INF || dist[k][j] == INF) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

            }

        }

    }

    while (q--) {

        cin >> a >> b;
        
        if (dist[a][b] != INF) cout << dist[a][b] << "\n";
        else cout << "-1\n";

    }

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