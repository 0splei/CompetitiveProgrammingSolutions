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

    ll n, x, ans, suma = 0;
    vl values;
    bool positive = false;

    cin >> n >> x;

    ans = x;
    values.pb(x);
    if (x > 0) positive = true;

    for (ll i = 1; i < n; i++) {

        cin >> x;
        ans = max(ans, x);
        values.pb(x);
        if (x > 0) positive = true;

    }

    if (positive == false) {

        cout << ans << "\n";
        return;

    }

    for (ll i = 0; i < n; i++) {

        suma = max({0LL, suma + values[i]});
        ans = max(ans, suma);

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