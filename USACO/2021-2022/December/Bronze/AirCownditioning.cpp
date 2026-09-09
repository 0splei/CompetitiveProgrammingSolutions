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

    ll n, x, ans = 0;
    vl t, p, difference;

    cin >> n;
    
    for (ll i = 0; i < n; i++) {

        cin >> x;
        t.pb(x);
    
    }

    for (ll i = 0; i < n; i++) {

        cin >> x;
        p.pb(x);

    }

    difference.pb(0);
    for (ll i = 0; i < n; i++) difference.pb(p[i] - t[i]);
    difference.pb(0);

    for (ll i = 0; i <= n; i++) ans += abs(difference[i] - difference[i + 1]);

    cout << ans / 2 << "\n";

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