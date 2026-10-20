
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

vl graph[205];
ll cap[205][205];
bool seen[205];

void addEdge (ll a, ll b, ll c) {

    graph[a].pb(b);
    graph[b].pb(a);

    cap[a][b] += c;

}

bool dfs (ll node, ll sink) {

    if (node == sink) return true;

    seen[node] = true;

    for (auto i : graph[node]) {

        if (seen[i] || cap[node][i] == 0) continue;

        if (dfs(i, sink)) {

            cap[node][i]--;
            cap[i][node]++;

            return true;

        }

    }

    return false;

}

void SOLVE(){

    ll n, s, e, a, b, m;
    cin >> n >> s >> e;

    ll source = 0, sink = 2 * n + 1;

    for (ll i = 1; i <= n; i++) {

        addEdge(i, i + n, 1);

    }

    for (ll i = 0; i < s; i++) {

        cin >> a;
        addEdge(source, a, 1);

    }

    for (ll i = 0; i < e; i++) {

        cin >> a;
        addEdge(a + n, sink, 1);

    }

    cin >> m;

    while (m--) {

        cin >> a >> b;
        addEdge(a + n, b, 1);

    }

    ll ans = 0;

    while (true) {

        memset(seen, false, sizeof(seen));

        if (!dfs(source, sink)) break;

        ans++;

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