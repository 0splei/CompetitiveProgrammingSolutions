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

    ll n, x, w;
    vl weight;

    cin >> n >> x;

    for (ll i = 0; i < n; i++) {

        cin >> w;
        weight.pb(w);

    }

    sort(weight.begin(), weight.end());

    ll l = 0, r = n - 1, ans = 0;

    while (l <= r) {

        if (weight[l] + weight[r] <= x) {

            ans++;
            l++;
            r--;

        } else {

            ans++;
            r--;

        }

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