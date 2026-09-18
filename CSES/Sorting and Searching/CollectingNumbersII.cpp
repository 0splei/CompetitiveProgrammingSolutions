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

    ll n, m, x, a, b, ans = 0, act = 0;
    
    cin >> n >> m;
    vl appears(n + 5), position(n + 5);

    for (ll i = 0; i < n; i++) {

        cin >> x;
        appears[x] = i + 1;
        position[i + 1] = x;

    }

    act = appears[1];
    ans = 1;

    for (ll i = 2; i <= n; i++) {

        if (act > appears[i]) ans++;
        act = appears[i];

    }

    // Position[i]: Que valor ocupa la posicion i
    // Appears[i]: En que posicion aparece el valor i

    while (m--) {

        cin >> a >> b;

        ll x = position[a], y = position[b];

        set <ll> check;
        check.insert(x - 1), check.insert(x), check.insert(y - 1), check.insert(y);

        for (auto i : check) {

            if (i >= 1 && i < n) {

                if (appears[i] > appears[i + 1]) ans--;

            }

        }

        swap(position[a], position[b]);
        swap(appears[x], appears[y]);

        for (auto i : check) {

            if (i >= 1 && i < n) {

                if (appears[i] > appears[i + 1]) ans++;

            }

        }

        cout << ans << "\n";
    
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