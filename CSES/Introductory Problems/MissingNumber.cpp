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
    vl values;

    cin >> n;

    for (ll i = 0; i < n - 1; i++) {

        cin >> x;
        values.pb(x);

    }

    sort(values.begin(), values.end());

    for (ll i = 0; i < n - 1; i++) {

        if (values[i] != i + 1) {

            cout << i + 1 << "\n";
            return;

        }

    }

    cout << n << "\n";

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