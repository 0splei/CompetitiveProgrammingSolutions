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
    
    ll n, ans = 0, left = 0, right = 0;
    bool h = false, g = false;
    string p;
    vl gDistance, hDistance;
    gDistance.pb(-1);
    hDistance.pb(-1);
    
    cin >> n >> p;
    
    for (ll i = 0; i < n; i++) {

        if (p[i] == 'G') {

            gDistance.pb(i);
            g = true;

        } else {

            hDistance.pb(i);
            h = true;

        }

    }

    gDistance.pb(n);
    hDistance.pb(n);

    if (!g || !h) {

        cout << "0\n";
        return;

    }

    for (ll i = 1; i < gDistance.size() - 1; i++) {

        left = gDistance[i] - gDistance[i - 1], right = gDistance[i + 1] - gDistance[i];
        ll act = left * right;
        act--;

        if (left > 1) act--;
        if (right > 1) act--;

        ans += act;

    }

    for (ll i = 1; i < hDistance.size() - 1; i++) {

        left = hDistance[i] - hDistance[i - 1], right = hDistance[i + 1] - hDistance[i];
        ll act = left * right;
        act--;

        if (left > 1) act--;
        if (right > 1) act--;

        ans += act;

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