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

    ll x;
    vl values;

    for (ll i = 0; i < 7; i++) {

        cin >> x;
        values.pb(x);

    }

    sort(values.begin(), values.end());

    cout << values[0] << " " << values[1] << " " << values[6] - (values[0] + values[1]) << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  //cin >> t;
  while(t--){
    SOLVE();
  }
}