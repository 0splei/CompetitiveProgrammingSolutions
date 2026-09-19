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

    ll x, n, p;
    set <ll> lights;
    multiset <ll> distances;

    cin >> x >> n;
    lights.insert(0);
    lights.insert(x);
    distances.insert(x);

    for (ll i = 0; i < n; i++) {

        cin >> p;

        auto low = lights.upper_bound(p);
        auto high = low;
        --low;

        distances.erase(distances.find(*(high) - *(low)));
        distances.insert(*(high) - p);
        distances.insert(p - *(low));

        lights.insert(p);

        cout << *(--distances.end()) << " ";

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