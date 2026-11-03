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

struct DSU {

    vector<int> e;

    DSU(int n) : e(n, -1) {}

    int Find(int i) {

        return e[i] < 0 ? i : e[i] = Find(e[i]);

    }

    bool Union(int i, int j) {

        int x = Find(i), y = Find(j);

        if (x == y) return false;

        if (e[y] < e[x]) swap(x, y);

        e[x] += e[y];
        e[y] = x;

        return true;

    }

};

const ll N = 2e5 + 5;
const ll LOG = 20;

DSU UF(N);

vll graph[N];

ll n, m, q;
ll depth[N];
ll up[N][LOG], mx[N][LOG];

void build() {

    vl order;

    for (ll i = 1; i <= n; i++) {

        if (depth[i]) continue;

        order.clear();
        order.pb(i);
        depth[i] = 1;

        for (ll j = 0; j < (ll)order.size(); j++) {

            ll act = order[j];

            for (auto next : graph[act]) {

                ll v = next.F;
                ll w = next.S;

                if (depth[v]) continue;

                depth[v] = depth[act] + 1;

                up[v][0] = act;
                mx[v][0] = w;

                order.pb(v);

            }

        }

    }

    for (ll j = 1; j < LOG; j++) {

        for (ll i = 1; i <= n; i++) {

            ll p = up[i][j - 1];

            up[i][j] = up[p][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[p][j - 1]);

        }

    }

}

ll query(ll a, ll b) {

    if (UF.Find(a) != UF.Find(b)) return -1;

    ll ans = 0;

    if (depth[a] < depth[b]) swap(a, b);

    ll dif = depth[a] - depth[b];

    for (ll j = LOG - 1; j >= 0; j--) {

        if ((dif >> j) & 1) {

            ans = max(ans, mx[a][j]);
            a = up[a][j];

        }

    }

    if (a == b) return ans;

    for (ll j = LOG - 1; j >= 0; j--) {

        if (up[a][j] != up[b][j]) {

            ans = max(ans, mx[a][j]);
            ans = max(ans, mx[b][j]);

            a = up[a][j];
            b = up[b][j];

        }

    }

    ans = max(ans, mx[a][0]);
    ans = max(ans, mx[b][0]);

    return ans;

}

void SOLVE(){

    cin >> n >> m >> q;

    for (ll i = 1; i <= m; i++) {

        ll a, b;
        cin >> a >> b;

        if (UF.Union(a, b)) {

            graph[a].pb({b, i});
            graph[b].pb({a, i});

        }

    }

    build();

    while (q--) {

        ll a, b;
        cin >> a >> b;

        cout << query(a, b) << "\n";

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