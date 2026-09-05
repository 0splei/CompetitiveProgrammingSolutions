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

bool cmp (const pair <LL, ll> &a, const pair <LL, ll> &b) {

    return a.F.S < b.F.S;

}

void SOLVE(){

    vector < pair <LL, ll> > norte, este;
    char c;
    ll n, x, y, ans[55];
    bool mueve[55];

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> c >> x >> y;

        if (c == 'E') este.pb({{x, y}, i});
        else norte.pb({{x, y}, i});

        ans[i] = LLONG_MAX;
        mueve[i] = true;

    }

    sort(este.begin(), este.end(), cmp);
    sort(norte.begin(), norte.end());

    for (ll j = 0; j < norte.size(); j++) {

        for (ll i = 0; i < este.size(); i++) {

            ll distancia_x = norte[j].F.F - este[i].F.F, distancia_y = este[i].F.S - norte[j].F.S;
            
            if (distancia_x > 0 && distancia_y > 0) {
                
                if (distancia_x > distancia_y && mueve[este[i].S] == true) {
                    
                    ans[este[i].S] = min(ans[este[i].S], distancia_x);
                    mueve[este[i].S] = false;

                } else if (distancia_x < distancia_y && mueve[este[i].S] == true) {

                    ans[norte[j].S] = min(ans[norte[j].S], distancia_y);
                    mueve[norte[j].S] = false;
                    break;

                } else continue;

            }

        }

    }

    for (ll i = 0; i < n; i++) {

        if (ans[i] != LLONG_MAX) cout << ans[i] << "\n";
        else cout << "Infinity\n";

    }

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