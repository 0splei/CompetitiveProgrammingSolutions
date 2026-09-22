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

    ll n, a, b, total = 0;
    vector < pair <LL, ll> > values;

    cin >> n;
    ll ans[n + 5];

    for (ll i = 0; i < n; i++) {

        cin >> a >> b;
        values.pb({{a, b}, i});

    }

    sort(values.begin(), values.end());
    priority_queue < LL > rooms;
    // Tiempo de salida - Cuarto
    total++;
    rooms.push({-values[0].F.S, total});
    ans[values[0].S] = total;

    for (ll i = 1; i < n; i++) {

        auto act = rooms.top();

        if (-act.F >= values[i].F.F) {

            total++;
            rooms.push({-values[i].F.S, total});
            ans[values[i].S] = total;
            
        } else {

            rooms.pop();
            rooms.push({-values[i].F.S, act.S});
            ans[values[i].S] = act.S;

        }

    }

    cout << total << "\n";
    for (ll i = 0; i < n; i++) cout << ans[i] << " ";

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