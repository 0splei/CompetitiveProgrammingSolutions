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

    ll n, k, x;
    vl values;
    map <ll, ll> appears;
    set <ll> used;

    cin >> n >> k;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    ll l = 0, r = 0, ans = 0;

    while (r < n) {

        used.insert(values[r]);
        appears[values[r]]++;

        while (l < r && used.size() > k) {

            appears[values[l]]--;
            if (appears[values[l]] == 0) used.erase(values[l]);
            l++;

        }

        ans += r + 1 - l;
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