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

    ll n, a, ans = 0;
    vl values;
    map <ll, ll> works;

    cin >> n;
    values.pb(0);

    for (ll i = 0; i < n; i++) {

        cin >> a;
        values.pb((values[i] + a) % n);

    }

    works[0] = 1;

    for (ll i = 1; i <= n; i++) {

        ans += works[(n - values[i]) % n];
        works[(n - values[i]) % n]++;

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