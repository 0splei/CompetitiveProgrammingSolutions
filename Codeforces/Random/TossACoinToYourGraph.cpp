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

ll n, m, k, u, v;
vl graph[200005], values;

bool kahn (ll x) {

    vl inDegree(n, 0), dp(n, 0);
    queue <ll> q;

    ll valid = 0, seen = 0;

    for (ll i = 0; i < n; i++) {

        if (values[i] <= x) {

            valid++;
            dp[i] = 1;

        }

    }

    for (ll i = 0; i < n; i++) {

        if (values[i] > x) continue;

        for (auto j : graph[i]) {

            if (values[j] <= x) {

                inDegree[j]++;

            }

        }

    }

    for (ll i = 0; i < n; i++) {

        if (values[i] <= x && inDegree[i] == 0) q.push(i);

    }

    while (!q.empty()) {

        ll act = q.front();
        q.pop();

        seen++;

        if (dp[act] >= k) return true;

        for (auto i : graph[act]) {

            if (values[i] > x) continue;

            dp[i] = max(dp[i], dp[act] + 1);

            inDegree[i]--;

            if (inDegree[i] == 0) q.push(i);

        }

    }

    return seen < valid;

}

void SOLVE() {

    cin >> n >> m >> k;

    for (ll i = 0; i < n; i++) {

        ll a;
        cin >> a;
        values.pb(a);

    }

    for (ll i = 0; i < m; i++) {

        cin >> u >> v;
        u--;
        v--;

        graph[u].pb(v);

    }

    vl candidates = values;

    sort(candidates.begin(), candidates.end());

    candidates.erase(
        unique(candidates.begin(), candidates.end()),
        candidates.end()
    );

    ll l = 0, r = candidates.size() - 1;
    ll ans = -1;

    while (l <= r) {

        ll mid = l + (r - l) / 2;

        if (kahn(candidates[mid])) {

            ans = candidates[mid];
            r = mid - 1;

        } else {

            l = mid + 1;

        }

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