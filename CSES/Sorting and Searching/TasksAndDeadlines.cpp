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

    ll n, a, d, ans = 0;
    vll values;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> a >> d;
        values.pb({a, d});

    }

    sort(values.begin(), values.end());

    ll time = 0;

    for (ll i = 0; i < n; i++) {

        time += values[i].F;
        ans += values[i].S - time;

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