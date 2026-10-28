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

struct nodes {

    ll adds, sets;
    bool hasSet;

};

ll n, q, t, x, a, b, ST[(ll) (8 * 1e5 + 5)];
nodes lazy[(ll) (8 * 1e5 + 5)];
vl values;

void build (ll left, ll right, ll node) {

    if (left == right) {

        ST[node] = values[left];
        lazy[node] = {0, 0, 0};
        return;

    }

    ll mid = (left + right) / 2;

    build (left, mid, (node * 2) + 1);
    build (mid + 1, right, (node * 2) + 2);

    ST[node] = ST[(node * 2) + 1] + ST[(node * 2) + 2];
    lazy[node] = {0, 0, 0};

}

void push (ll left, ll right, ll node) {

    if ((lazy[node].adds == 0 && !lazy[node].hasSet) || left == right) return;

    ll mid = (left + right) / 2, leftChild = (node * 2) + 1, rightChild = (node * 2) + 2;

    if (lazy[node].hasSet) {
        
        ST[leftChild] = (lazy[node].sets + lazy[node].adds) * (mid + 1 - left);
        ST[rightChild] = (lazy[node].sets + lazy[node].adds) * (right - mid);
        
        lazy[leftChild] = lazy[node];
        lazy[rightChild] = lazy[node];

    } else {

        ST[leftChild] += lazy[node].adds * (mid + 1 - left);
        ST[rightChild] += lazy[node].adds * (right - mid);

        lazy[leftChild].adds += lazy[node].adds;
        lazy[rightChild].adds += lazy[node].adds;

    }

    lazy[node] = {0, 0, 0};

}

void update (ll left, ll right, ll node, ll l, ll r, ll val, bool hasSet) {

    if (left > r || right < l) return;

    if (left >= l && right <= r) {
        
        if (hasSet) {
            
            ST[node] = val * (right + 1 - left);
            lazy[node] = {0, val, true};

        } else {

            ST[node] += val * (right + 1 - left);
            lazy[node].adds += val;

        }

        return;

    }

    push (left, right, node);

    ll mid = (left + right) / 2;

    update (left, mid, (node * 2) + 1, l, r, val, hasSet);
    update (mid + 1, right, (node * 2) + 2, l, r, val, hasSet);

    ST[node] = ST[(node * 2) + 1] + ST[(node * 2) + 2];

}

ll query (ll left, ll right, ll node, ll l, ll r) {

    if (left > r || right < l) return 0;

    if (left >= l && right <= r) return ST[node];

    push (left, right, node);

    ll mid = (left + right) / 2;

    return query(left, mid, (node * 2) + 1, l, r) + query(mid + 1, right, (node * 2) + 2, l, r);

}

void SOLVE(){

    cin >> n >> q;

    for (ll i = 0; i < n; i++) {

        cin >> t;
        values.pb(t);

    }

    build (0, n - 1, 0);

    ll op;

    while (q--) {

        cin >> op;

        if (op == 1) {

            cin >> a >> b >> x;
            a--;
            b--;

            update(0, n - 1, 0, a, b, x, false);

        } else if (op == 2) {

            cin >> a >> b >> x;
            a--;
            b--;

            update(0, n - 1, 0, a, b, x, true);

        } else {

            cin >> a >> b;
            a--;
            b--;

            cout << query(0, n - 1, 0, a, b) << "\n";

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