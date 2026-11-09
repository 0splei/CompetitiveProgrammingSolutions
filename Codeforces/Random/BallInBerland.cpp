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

    ll a, b, k, x;
    map <ll, ll> boys, girls;

    cin >> a >> b >> k;

    for (ll i = 0; i < k; i++) {

        cin >> x;
        boys[x]++;

    }

    for (ll i = 0; i < k; i++) {

        cin >> x;
        girls[x]++;
        
    }

    ll ans = (k * (k - 1)) / 2;

    for (auto i : boys) ans -= (i.S * (i.S - 1)) / 2;
    for (auto i : girls) ans -= (i.S * (i.S - 1)) / 2;

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