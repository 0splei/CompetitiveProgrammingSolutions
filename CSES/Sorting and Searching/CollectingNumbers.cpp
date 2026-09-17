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

    ll n, x, ans = 0, act = 0;
    map <ll, ll> position;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        position[x] = i;

    }

    act = position[1];
    ans = 1;

    for (ll i = 2; i <= n; i++) {

        if (act > position[i]) ans++;
        act = position[i];

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