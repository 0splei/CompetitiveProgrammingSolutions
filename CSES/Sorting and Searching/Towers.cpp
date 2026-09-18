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

    ll n, k;
    vl values;
    multiset <ll> towers;

    cin >> n >> k;
    towers.insert(k);

    for (ll i = 1; i < n; i++) {

        cin >> k;
        
        auto it = towers.upper_bound(k);

        if (it == towers.end()) towers.insert(k);
        else {

            towers.erase(it);
            towers.insert(k);

        }

    }

    cout << towers.size() << "\n";

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