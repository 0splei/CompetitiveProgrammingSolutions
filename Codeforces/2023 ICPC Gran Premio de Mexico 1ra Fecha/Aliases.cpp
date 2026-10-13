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

    ll n, x, ans = 0;
    string p, act;
    map <string, ll> NAME;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        act = "";

        while (x--) {

            cin >> p;
            act += p[0];

        }

        NAME[act]++;

    }

    for (auto i : NAME) if (i.S == 1) ans++;

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