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

const ll N = 2 * 1e5 + 5;

vl graph[N], order, values;
ll ST[4 * N], n, q, a, b, s, v, x, treeIn[N], treeOut[N], timer = 0, totSum = 0, suma[N], lazy[4 * N];
bool seen[N];

void dfs (ll node) {

    if (seen[node]) return;

    seen[node] = true;

    order.pb(node);
    totSum += values[node];
    suma[node] = totSum;
    treeIn[node] = timer;
    timer++;

    for (auto i : graph[node]) dfs(i);

    treeOut[node] = timer - 1;
    totSum -= values[node];

}

void push (ll left, ll right, ll node) {

    if (lazy[node] == 0 || left == right) return;

    ll mid = (left + right) / 2, leftChild = (node * 2) + 1, rightChild = (node * 2) + 2;

    ST[leftChild] += lazy[node] * (mid + 1 - left);
    ST[rightChild] += lazy[node] * (right - mid);

    lazy[leftChild] += lazy[node];
    lazy[rightChild] += lazy[node];

    lazy[node] = 0;

}

void build (ll left, ll right, ll node) {

    if (left == right) {

        ST[node] = suma[order[left]];
        return;

    }

    ll mid = (left + right) / 2;

    build (left, mid, (node * 2) + 1);
    build (mid + 1, right, (node * 2) + 2);

    ST[node] = ST[(node * 2) + 1] + ST[(node * 2) + 2];

}

void update (ll left, ll right, ll node, ll l, ll r, ll dif) {

    if (left > r || right < l) return;

    if (left >= l && right <= r) {

        ST[node] += dif * (right + 1 - left);
        lazy[node] += dif;
        return;

    }

    push (left, right, node);

    ll mid = (left + right) / 2;

    update (left, mid, (node * 2) + 1, l, r, dif);
    update (mid + 1, right, (node * 2) + 2, l, r, dif);

    ST[node] = ST[(node * 2) + 1] + ST[(node * 2) + 2];

}

ll query (ll left, ll right, ll node, ll obj) {

    if (left > obj || right < obj) return 0;

    if (left == obj && right == obj) return ST[node];

    push (left, right, node);

    ll mid = (left + right) / 2;

    return query(left, mid, (node * 2) + 1, obj) + query(mid + 1, right, (node * 2) + 2, obj);

}

void SOLVE(){

    cin >> n >> q;

    values.pb(0);

    for (ll i = 0; i < n; i++) {

        cin >> v;
        values.pb(v);

    }

    for (ll i = 0; i < n - 1; i++) {

        cin >> a >> b;

        graph[a].pb(b);
        graph[b].pb(a);

    }

    memset(seen, false, sizeof(seen));
    memset(lazy, 0, sizeof(lazy));
    dfs(1);
    build(0, n - 1, 0);

    while (q--) {

        ll op;
        cin >> op;

        if (op == 1) {

            cin >> s >> x;

            update(0, n - 1, 0, treeIn[s], treeOut[s], x - values[s]);
            values[s] = x;

        } else {

            cin >> s;

            cout << query(0, n - 1, 0, treeIn[s]) << "\n";

        }

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