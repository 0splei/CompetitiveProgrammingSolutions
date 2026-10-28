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

ll n, q, x, u, k, a, b, ST[(ll) (4 * (2 * 1e5 + 5))], lazy[(ll) (4 * (2 * 1e5 + 5))], op;
vl values;

void push (ll left, ll right, ll node) {

    if (lazy[node] == 0 || left == right) return;

    ll mid = (left + right) / 2, leftChild = node * 2 + 1, rightChild = node * 2 + 2;

    ST[leftChild] += lazy[node] * (mid + 1 - left);
    ST[rightChild] += lazy[node] * (right - mid);

    lazy[leftChild] += lazy[node];
    lazy[rightChild] += lazy[node];

    lazy[node] = 0;

}

void update(ll left, ll right, ll node, ll l, ll r, ll val) {

    if (left > r || right < l) return;

    if (left >= l && right <= r) {

        ST[node] += val * (right - left + 1);
        lazy[node] += val;

        return;

    }

    push(left, right, node);

    ll mid = (left + right) / 2;

    update(left, mid, node * 2 + 1, l, r, val);
    update(mid + 1, right, node * 2 + 2, l, r, val);

    ST[node] = ST[node * 2 + 1] + ST[node * 2 + 2];

}

void query (ll left, ll right, ll node, ll obj) {

    if (left > obj || right < obj) return;

    if (left == obj && right == obj) {

        values[obj] += ST[node];
        ST[node] = 0;
        return;
    
    }

    push(left, right, node);

    ll mid = (left + right) / 2;

    query(left, mid, node * 2 + 1, obj);
    query(mid + 1, right, node * 2 + 2, obj);

}

void SOLVE(){

    cin >> n >> q;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    memset(ST, 0, sizeof(ST));
    memset(lazy, 0, sizeof(lazy));

    while (q--) {

        cin >> op;

        if (op == 1) {

            cin >> a >> b >> u;
            a--;
            b--;

            update (0, n - 1, 0, a, b, u);

        } else {

            cin >> k;
            k--;

            query(0, n - 1, 0, k);

            cout << values[k] << "\n";

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