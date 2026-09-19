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

    ll n, x, ans = 1, mod = 1e9 + 7;
    map <ll, ll> appears;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        appears[x]++;

    }

    for (auto i : appears) {

        ans *= (i.S + 1) % mod;
        ans %= mod;

    }

    cout << ans - 1 << "\n";

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