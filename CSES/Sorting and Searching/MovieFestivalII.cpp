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

    ll n, k, a, b, ans = 0;
    vll values;
    multiset <ll> members;

    cin >> n >> k;

    for (ll i = 0; i < n; i++) {

        cin >> a >> b;
        values.pb({b, a});

    }

    sort(values.begin(), values.end());

    while (k--) {

        members.insert(0);

    }

    for (ll i = 0; i < n; i++) {

        auto it = members.upper_bound(values[i].S);

        if (it != members.begin()) {

            ans++;
            members.erase(--it);
            members.insert(values[i].F);

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