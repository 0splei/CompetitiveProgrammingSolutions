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

LL ST[(ll) (4 * ((2* 1e5) + 5))];
ll n, q, p, x, o, k, INF = 1e9;
vl values;

void build (ll left, ll right, ll node) {

    if (left == right) {

        ST[node].F = values[left] - left;
        ST[node].S = values[right] + right;
        return;

    }

    ll mid = (left + right) / 2;
    
    build(left, mid, (node * 2) + 1);
    build(mid + 1, right, (node * 2) + 2);

    LL leftChild = ST[(node * 2) + 1], rightChild = ST[(node * 2) + 2];

    ST[node] = {min(leftChild.F, rightChild.F), min(leftChild.S, rightChild.S)};

}

ll querieLeft (ll left, ll right, ll l, ll r, ll node) {

    if (left > r || right < l) return INF;

    if (left >= l && right <= r) return ST[node].F + k;

    ll mid = (left + right) / 2;

    return min(querieLeft(left, mid, l, r, (node * 2) + 1), querieLeft(mid + 1, right, l, r, (node * 2) + 2));

}

ll querieRight (ll left, ll right, ll l, ll r, ll node) {

    if (left > r || right < l) return INF;

    if (left >= l && right <= r) return ST[node].S - k;

    ll mid = (left + right) / 2;

    return min(querieRight(left, mid, l, r, (node * 2) + 1), querieRight(mid + 1, right, l, r, (node * 2) + 2));
    
}

void update (ll left, ll right, ll node, ll pos) {

    if (left > pos || right < pos) return;

    if (left == right) {

        ST[node].F = values[left] - left;
        ST[node].S = values[right] + right;
        return;

    }

    ll mid = (left + right) / 2;
    
    update(left, mid, (node * 2) + 1, pos);
    update(mid + 1, right, (node * 2) + 2, pos);

    LL leftChild = ST[(node * 2) + 1], rightChild = ST[(node * 2) + 2];

    ST[node] = {min(leftChild.F, rightChild.F), min(leftChild.S, rightChild.S)};

}

void SOLVE(){

    cin >> n >> q;

    for (ll i = 0; i < n; i++) {

        cin >> p;
        values.pb(p);

    }

    build (0, n - 1, 0);

    while (q--) {

        cin >> o;

        if (o == 1) {

            cin >> k >> x;

            values[k - 1] = x;
            update(0, n - 1, 0, k - 1);

        } else {

            cin >> k;
            k--;

            cout << min(querieLeft(0, n - 1, 0, k, 0), querieRight(0, n - 1, k, n - 1, 0)) << "\n";

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