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

    ll n, x, a, total = 0, ans = 0;
    vl values;
    map <ll, ll> possible;

    cin >> n >> x;

    for (ll i = 0; i < n; i++) {

        cin >> a;
        values.pb(a);

    }

    total = 0;
    possible[0] = 1;
    
    for (ll i = 0; i < n; i++) {

        total += values[i];
        ans += possible[total - x];
        possible[total]++;

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