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

    if (a.F.F == b.F.F) return a.F.S > b.F.S;
    return a.F.F < b.F.F;

}

void SOLVE(){

    ll n, x, y, maxR = 0, minR = 1e9 + 5;
    bool contains[ll (2 * 1e5 + 5)] = {false}, isContained[ll (2 * 1e5 + 5)] = {false};
    vector < pair <LL, ll> > values;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x >> y;
        values.pb({{x, y}, i});

    }

    sort(values.begin(), values.end(), cmp);

    for (ll i = 0; i < n; i++) {

        if (maxR >= values[i].F.S) isContained[values[i].S] = true;

        maxR = max(maxR, values[i].F.S);

    }

    for (ll i = n - 1; i >= 0; i--) {

        if (minR <= values[i].F.S) contains[values[i].S] = true;

        minR = min(minR, values[i].F.S);

    }

    for (ll i = 0; i < n; i++) cout << (ll) contains[i] << " ";
    cout << "\n";
    for (ll i = 0; i < n; i++) cout << (ll) isContained[i] << " ";

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