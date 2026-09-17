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

    ll n, m, x;
    multiset <ll> price;

    cin >> n >> m;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        price.insert(x);

    }

    for (ll j = 0; j < m; j++) {

        cin >> x;
        
        auto pos = price.upper_bound(x);

        if (pos == price.begin()) {

            cout << "-1\n";

        } else {
            
            cout << *(--pos) << "\n";
            price.erase(pos);
        
        }

    }

}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int t = 1;
  //cin >> t;
  while(t--){
    SOLVE();
  }
  return 0;
}