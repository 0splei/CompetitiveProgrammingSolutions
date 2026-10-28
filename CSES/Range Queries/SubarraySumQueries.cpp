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

    ll maxPrefix, maxSufix, maxSum, totalSum;

};

nodes ST[(ll) (4 * (2 * 1e5 + 5))];
ll n, m, x, k;
vl values;

void setNode (ll node) {

    ll leftSon = (node * 2) + 1, rightSon = (node * 2) + 2;

    ll maxPrefix = max({
                        ST[leftSon].maxPrefix,
                        ST[leftSon].totalSum,
                        ST[leftSon].totalSum + ST[rightSon].maxPrefix,
                        ST[leftSon].totalSum + ST[rightSon].totalSum
                        });

    ll maxSufix = max({
                        ST[rightSon].maxSufix,
                        ST[rightSon].totalSum,
                        ST[rightSon].totalSum + ST[leftSon].maxSufix,
                        ST[leftSon].totalSum + ST[rightSon].totalSum
    });

    ll totalSum = ST[leftSon].totalSum + ST[rightSon].totalSum;

    ll maxSum = max({maxPrefix, maxSufix, ST[rightSon].maxSum, ST[leftSon].maxSum, totalSum, ST[rightSon].maxPrefix + ST[leftSon].maxSufix});

    ST[node] = {maxPrefix, maxSufix, maxSum, totalSum};

}

void build (ll left, ll right, ll node) {

    if (left == right) {

        ST[node] = {values[left], values[left], values[left], values[left]};
        return;

    }

    ll mid = (left + right) / 2;

    build(left, mid, (node * 2) + 1);
    build(mid + 1, right, (node * 2) + 2);

    setNode(node);

}

void update (ll left, ll right, ll node, ll pos) {

    if (left > pos || right < pos) return;

    if (left == pos && right == pos) {

        ST[node] = {values[left], values[left], values[left], values[left]};
        return;

    }

    ll mid = (left + right) / 2;

    update(left, mid, (node * 2) + 1, pos);
    update(mid + 1, right, (node * 2) + 2, pos);

    setNode(node);

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    build (0, n - 1, 0);

    while (m--) {

        cin >> k >> x;
        k--;

        values[k] = x;
        update(0, n - 1, 0, k);
        cout << max(0LL, ST[0].maxSum) << "\n";

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