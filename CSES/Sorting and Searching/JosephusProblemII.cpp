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

void SOLVE(){

    ll n, k, pos = 0;
    ordered_set <ll> kids;

    cin >> n >> k;

    for (ll i = 1; i <= n; i++) kids.insert(i);

    while (!kids.empty()) {

        pos = (pos + k) % kids.size();
        auto it = kids.find_by_order(pos);
        cout << *it << " ";
        kids.erase(it);

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