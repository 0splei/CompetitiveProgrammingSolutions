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

    ll n;
    cin >> n;

    vl pos(1001, -1), vals;

    for (ll i = 1; i <= n; i++){
        
        ll x;
        cin >> x;

        if(pos[x] == -1){
            
            vals.pb(x);
        
        }

        pos[x] = i;
    
    }

    ll ans = -1;

    for (ll x : vals) {
        
        for (ll y : vals) {

            if (gcd(x, y) == 1){

                ans = max(ans, pos[x] + pos[y]);
            
            }

        }

    }

    cout << ans << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--){
    SOLVE();
  }
  return 0;
}