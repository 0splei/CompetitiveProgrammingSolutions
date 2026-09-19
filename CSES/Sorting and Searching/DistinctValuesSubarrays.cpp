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

    ll n, x, ans = 0, tam = 0;
    vl values;
    set <ll> appears;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    ll l = 0, r = 0;

    while (r < n) {
            
        while (appears.count(values[r])) {
                
            appears.erase(values[l]);
            l++;
                
        }
        
        ans += r - l + 1;
        appears.insert(values[r]);
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