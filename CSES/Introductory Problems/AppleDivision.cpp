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

ll n, p, total = 0;
vl values;

ll best (ll pos, ll group) {

    if (pos >= n) return abs(abs(total - group) - group);
    return min(best(pos + 1, group + values[pos]), best(pos + 1, group));

}

void SOLVE(){

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> p;
        values.pb(p);
        total += p;

    }

    cout << best(0, 0) << "\n";

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