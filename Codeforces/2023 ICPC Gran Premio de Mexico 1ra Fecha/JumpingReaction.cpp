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

ll n, q, a, l, r, mod = 1e9 + 7;
vl sums, sumsSquared;

void SOLVE(){

	cin >> n >> q;
	sums.pb(0);
	sumsSquared.pb(0);

	for (ll i = 0; i < n; i++) {

		cin >> a;
		sums.pb((a + sums[sums.size() - 1]) % mod);
		sumsSquared.pb((((a * a) % mod) + sumsSquared[sumsSquared.size() - 1]) % mod);

	}

	while (q--) {

		cin >> l >> r;

		ll p1 = (sums[r] - sums[l - 1] + mod) % mod;
		p1 = (p1 * p1) % mod;

		ll p2 = (sumsSquared[r] - sumsSquared[l - 1] + mod) % mod;

		ll ans = (p1 - p2 + mod) % mod;

		cout << (ans * 500000004) % mod << "\n";

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