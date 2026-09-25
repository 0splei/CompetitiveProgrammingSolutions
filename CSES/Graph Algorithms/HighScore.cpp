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

const ll NEG_INF = -4e18;

struct Edge {

    ll a, b, w;

};

void SOLVE(){

    ll n, m, a, b, x;
    bool canReach[2505] = {false};
    vl reverseGraph[2505], dist(2505, NEG_INF);
    vector <Edge> edges;

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b >> x;
        edges.pb({a, b, x});
        reverseGraph[b].pb(a);

    }

    queue <ll> q;

    q.push(n);
    canReach[n] = true;

    while (!q.empty()) {

        ll act = q.front();
        q.pop();

        for (auto i : reverseGraph[act]) {

            if (canReach[i] == true) continue;

            canReach[i] = true;
            q.push(i);

        }

    }

    dist[1] = 0;

    for (ll i = 1; i <= n - 1; i++) {

        for (auto e : edges) {

            if (dist[e.a] == NEG_INF) continue;

            dist[e.b] = max(dist[e.b], dist[e.a] + e.w);

        }

    }

    for (auto e : edges) {

        if (dist[e.a] == NEG_INF) continue;

        if (dist[e.a] + e.w > dist[e.b] && canReach[e.b] == true) {

            cout << "-1\n";
            return;

        }

    }

    cout << dist[n] << "\n";

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