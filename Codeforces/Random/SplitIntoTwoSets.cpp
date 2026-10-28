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

ll n, a, b, color[(ll) (2 * 1e5 + 5)], appears[(ll) (2 * 1e5 + 5)];
bool possible;
vl graph[(ll) (2 * 1e5 + 5)], domino[(ll) (2 * 1e5 + 5)];

bool dfs (ll u, bool c) {

    color[u] = c;

    for (ll v : graph[u]) {

        if (color[v] == -1) {

            if (!dfs(v, !c)) return false;

        } else if (color[v] == color[u]) return false;

    }

    return true;

}

void SOLVE(){

    cin >> n;
    possible = true;

    for (ll i = 0; i <= n; i++) {

        graph[i].clear();
        domino[i].clear();
        appears[i] = 0;
        color[i] = -1;

    }

    for (ll i = 0; i < n; i++) {

        cin >> a >> b;

        if (a == b) possible = false;

        domino[a].pb(i);
        domino[b].pb(i);

        appears[a]++;
        appears[b]++;

    }

    for (ll x = 1; x <= n; x++) {

        if (appears[x] != 2) {

            cout << "NO\n";
            return;

        }

    }

    for (ll x = 1; x <= n; x++) {

        a = domino[x][0], b = domino[x][1];

        graph[a].pb(b);
        graph[b].pb(a);

    }

    for (ll i = 1; i <= n; i++) {

        if (color[i] == -1) {

            if (!dfs(i, 0)) {

                cout << "NO\n";
                return;

            }

        }

    }

    cout << "YES\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--){
    SOLVE();
  }
  return 0;
}