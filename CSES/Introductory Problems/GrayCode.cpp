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

    for (ll i = 0; i < (1 << n); i++) {

        ll ans = i ^ (i >> 1);
        
        for (ll j = n - 1; j >= 0; j--) {
            
            cout << ((ans >> j) & 1);

        }

        cout << "\n";

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