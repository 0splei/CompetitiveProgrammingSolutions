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

void SOLVE(){

	ll n, a, b;
	vl vacas, espacios;
	map <ll, ll> cabe;

	cin >> n;

	for (ll i = 0; i < n; i++) {

		cin >> a;
		vacas.pb(a);

	}

	for (ll i = 0; i < n; i++) {

		cin >> b;
		espacios.pb(b);

	}

	sort(vacas.begin(), vacas.end());
	reverse(vacas.begin(), vacas.end());
	sort(espacios.begin(), espacios.end());

	ll ans = 1;

	for (ll i = 0; i < n; i++) {

		for (ll j = 0; j < n; j++) if (espacios[j] >= vacas[i]) cabe[i]++;

	}

	for (ll i = 0; i < n; i++) {

		ans *= max(0LL, cabe[i] - i);

	}

	cout << ans << "\n";

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