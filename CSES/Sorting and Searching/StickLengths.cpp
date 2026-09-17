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

    ll n, p, suma = 0, median = 0, ans = 0, cnt = 0;
    vl values;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> p;
        suma += p;
        values.pb(p);

    }
    
    sort(values.begin(), values.end());

    if (n & 1) {

        median = values[n / 2];
        for (ll i = 0; i < n; i++) cnt += abs(median-values[i]);
        ans = cnt;

    } else {

        median = values[(n / 2) - 1];
        for (ll i = 0; i < n; i++) cnt += abs(median-values[i]);
        ans = cnt;
        cnt = 0;
        median = values[n / 2];
        for (ll i = 0; i < n; i++) cnt += abs(median-values[i]);
        ans = min(ans, cnt);

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