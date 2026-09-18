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

    ll n, k, ans = 1, l = 0, r = 0;
    vl values;
    set <ll> appears;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> k;
        values.pb(k);

    }

    while (l < n) {

        while (l < n && appears.count(values[r])) {

            appears.erase(values[l]);
            l++;

        }

        if (l > r && l < n) {
            
            r = l;
            appears.clear();
            
        }
        
        appears.insert(values[r]);

        ans = max(r + 1 - l, ans);
        
        if (r + 1 < n) r++;

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