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

vl values;

bool check (ll obj, ll possible) {

	ll cnt = 0;

	for (auto i : values) {

		if (i >= obj) cnt++;
		else if (possible > 0 && i + 1 >= obj) {

			possible--;
			cnt++;

		}

	}

	return cnt >= obj;
}

void SOLVE(){
    ll n, l, x;

    cin >> n >> l;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    sort (values.begin(), values.end());
	reverse (values.begin(), values.end());

	ll left = 0, right = 1e5, mid;

	while (left + 1 < right) {

		mid = (left + right + 1) / 2;

		if (check(mid, l) == true) left = mid;
		else right = mid;

	}

	if (check(right, l) == true) cout << right << "\n";
	else cout << left << "\n";

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
