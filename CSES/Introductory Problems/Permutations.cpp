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

    ll n;

    cin >> n;

    if (n == 1) {

        cout << 1;
        return;

    } else if (n <= 3) {

        cout << "NO SOLUTION";
        return;
        
    }

    for (ll i = 2; i <= n; i += 2) cout << i << " ";
    for (ll i = 1; i <= n; i += 2) cout << i << " ";

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