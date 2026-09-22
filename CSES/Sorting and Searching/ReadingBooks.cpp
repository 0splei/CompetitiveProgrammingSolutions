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

    ll n, t, maxi = 0, total = 0;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> t;
        maxi = max(maxi, t);
        total += t;

    }

    cout << max(total, 2 * maxi) << "\n";

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