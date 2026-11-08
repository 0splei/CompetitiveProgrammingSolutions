#include <bits/stdc++.h>
#include <climits>

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

    ll n, a;

    cin >> n;

    while (n--) {

        ll ans = LLONG_MAX;
        cin >> a;

        for (ll i = 0; i <= 15; i++) {

            ll act = a + i, pot = 0;

            while (act % 32768 != 0) {

                act *= 2;
                pot++;

            }

            ans = min(ans, i + pot);

        }

        cout << ans << " ";

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