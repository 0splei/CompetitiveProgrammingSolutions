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

    ll n, x, suma = 0;
    vl values;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    sort(values.begin(), values.end());

    for (ll i = 0; i < n; i++) {

        if (suma + 1 < values[i]) {

			cout << suma + 1 << "\n";
			return;

		}

		suma += values[i];

    }

	cout << suma + 1 << "\n";

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