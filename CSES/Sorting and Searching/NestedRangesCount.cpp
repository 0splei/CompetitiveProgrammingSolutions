#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

bool cmp (const pair <LL, ll> &a, const pair <LL, ll> &b) {

    if (a.F.F == b.F.F) return a.F.S > b.F.S;
    return a.F.F < b.F.F;

}

void SOLVE(){

    ll n, x, y, maxR = 0, minR = 1e9 + 5;
    vector < pair <LL, ll> > values;
    
    cin >> n;
    ll contains[n + 5] = {0}, isContained[n + 5] = {0};

    for (ll i = 0; i < n; i++) {

        cin >> x >> y;
        values.pb({{x, y}, i});

    }

    sort(values.begin(), values.end(), cmp);
    ordered_set <LL> previous;

    for (ll i = 0; i < n; i++) {

        ll r = values[i].F.S, id = values[i].S;
        ll smaller = previous.order_of_key({r, LLONG_MIN});

        isContained[id] = previous.size() - smaller;

        previous.insert({r, id});

    }

    previous.clear();

    for (ll i = n - 1; i >= 0; i--) {

        ll r = values[i].F.S, id = values[i].S;
        ll smallerOrEqual = previous.order_of_key({r, LLONG_MAX});

        contains[id] = smallerOrEqual;

        previous.insert({r, id});

    }

    for (ll i = 0; i < n; i++) cout << (ll) contains[i] << " ";
    cout << "\n";
    for (ll i = 0; i < n; i++) cout << (ll) isContained[i] << " ";

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