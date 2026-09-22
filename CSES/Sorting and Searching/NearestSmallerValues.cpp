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

    ll n, x;
    vl values, current;
    
    cin >> n;
    ll ans[n + 5] = {0};

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);

    }

    current.pb(n - 1);

    for (ll i = n - 2; i >= 0; i--) {

        while (!current.empty() && values[current[current.size() - 1]] > values[i]) {

            ans[current[current.size() - 1]] = i + 1;
            current.pop_back();

        }

        current.pb(i);

    }

    for (ll i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";

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