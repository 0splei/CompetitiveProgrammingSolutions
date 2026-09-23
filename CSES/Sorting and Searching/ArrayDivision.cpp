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

ll n, k, x;
vl values;

bool check (ll maxi) {

    ll cnt = 0, total = 0;

    for (ll i = 0; i < n; i++) {

        if (total + values[i] > maxi) {

            total = values[i];
            cnt++;

        } else total += values[i];

    }

    return cnt < k;

} 

void SOLVE(){

    ll mini = 0, maxi = 0;

    cin >> n >> k;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        values.pb(x);
        mini = max(x, mini);
        maxi += values[i];

    }

    ll l = mini, r = maxi, mid, cnt = 0, total = 0;

    while (l + 1 < r) {

        mid = (l + r) / 2;

        if (check(mid)) r = mid;
        else l = mid;

    }

    if (check(l)) cout << l << "\n";
    else cout << r << "\n";

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