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

    ll n, x, pares = 0, impares = 0;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x;

        if (x & 1) impares++;
        else pares ++;

    }

    ll ans = 0;

    for (ll i = 0; i < n; i++) {

        if (i & 1) {
          
            if (impares != 0) {
             
                impares--;
                ans++;
            
            } else break;

        } else {

            if (pares > 0) {
            
                pares--;
                ans++;
            
            } else if (impares >= 2) {
                
                impares -= 2;
                ans++;
            
            } else if (impares == 1) {
                
                impares = 0;
                ans--;

            } else break;

        }

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