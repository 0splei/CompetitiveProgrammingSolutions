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

    ll n, x, a;
    vl values;

    cin >> n >> x;

    for (ll i = 0; i < n; i++) {

        cin >> a;
        values.pb(a);

    }

    ll l = 0, r = 0, act = 0, ans = 0;

    while (r < n) {

        while (l != r && (act + values[r]) > x) {

            act -= values[l];
            l++;

        }
        
        if (l > r) r = l;
        
        act += values[r];
        if (act == x) ans++;
        r++;

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