#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<LL> vll;

#define pb push_back
#define F first
#define S second

ll n, m, u, v, dp[300005]['z' + 5], ans = 0, seen = 0;
string p;
vl graph[300005], invertedGraph[300005];
map <ll, ll> inDegree;

void kahn () {

    queue <ll> q;

    for (ll i = 0; i < n; i++) if (inDegree[i] == 0) q.push(i);

    while (!q.empty()) {

        ll act = q.front();
        q.pop();

        for (auto i : invertedGraph[act]) {

            for (ll j = 'a'; j <= 'z'; j++) {

                dp[act][j] = max(dp[i][j], dp[act][j]);

            }

        }

        dp[act][p[act]]++;
        ans = max(dp[act][p[act]], ans);
        seen++;

        for (auto i : graph[act]) {

            inDegree[i]--;

            if (inDegree[i] == 0) {

                q.push(i);

            }

        }

    }

}

void SOLVE(){

    cin >> n >> m >> p;

    for (ll i = 0; i < m; i++) {

        cin >> u >> v;

        u--;
        v--;

        graph[u].pb(v);
        invertedGraph[v].pb(u);
        inDegree[v]++;

    }

    memset(dp, 0, sizeof(dp));
    kahn();

    if (seen != n) {

        cout << "-1\n";
        return;

    }

    cout << ans << "\n";

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