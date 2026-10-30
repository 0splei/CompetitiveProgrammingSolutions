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

ll n, q, p, x, v, ST[4 * N], treeIn[N], treeOut[N], timer = 0;
bool lazy[4 * N], seen[N];
vl values, order, graph[N];

void push (ll left, ll right, ll node) {

    if (!lazy[node] || left == right) return;

    ll mid = (left + right) / 2, leftChild = node * 2 + 1, rightChild = node * 2 + 2;

    ST[leftChild] = (mid + 1 - left) - ST[leftChild];
    ST[rightChild] = (right - mid) - ST[rightChild];

    lazy[leftChild] = !lazy[leftChild];
    lazy[rightChild] = !lazy[rightChild];

    lazy[node] = 0;

}

void update (ll left, ll right, ll node, ll l, ll r) {

    if (left > r || right < l) return;

    if (left >= l && right <= r) {

        ST[node] = (right - left + 1) - ST[node];
        lazy[node] = !lazy[node];

        return;

    }

    push (left, right, node);

    ll mid = (left + right) / 2;

    update(left, mid, (node * 2) + 1, l, r);
    update(mid + 1, right, (node * 2) + 2, l, r);

    ST[node] = ST[(node * 2) + 1] + ST[(node * 2) + 2];

}

ll query (ll left, ll right, ll node, ll l, ll r) {

    if (left > r || right < l) return 0;

    if (left >= l && right <= r) {

        return ST[node];
    
    }

    push(left, right, node);

    ll mid = (left + right) / 2;

    return query(left, mid, node * 2 + 1, l, r) + query(mid + 1, right, node * 2 + 2, l, r);

}

void build (ll left, ll right, ll node) {

    if (left == right) {

        ST[node] = values[order[left]];
        lazy[node] = 0;
        return;

    }

    ll mid = (left + right) / 2;

    build(left, mid, (node * 2) + 1);
    build(mid + 1, right, (node * 2) + 2);

    ST[node] = ST[(node * 2) + 1] + ST[(node * 2) + 2];
    lazy[node] = 0;

}

void dfs (ll node) {

    if (seen[node]) return;

    treeIn[node] = timer;
    order.pb(node);
    timer++;
    seen[node] = true;

    for (auto i : graph[node]) dfs(i);

    treeOut[node] = timer - 1;

}

void SOLVE(){

    cin >> n;

    for (ll i = 2; i <= n; i++) {

        cin >> p;
        graph[p].pb(i);

    }

    values.pb(0);

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    memset(seen, false, sizeof(seen));
    dfs(1);
    build(0, n - 1, 0);

    cin >> q;

    while (q--) {

        string op;

        cin >> op;

        if (op == "get") {

            cin >> v;

            cout << query(0, n - 1, 0, treeIn[v], treeOut[v]) << "\n";

        } else {

            cin >> v;

            update(0, n - 1, 0, treeIn[v], treeOut[v]);

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