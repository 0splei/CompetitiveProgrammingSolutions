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

    ll n, x, a;
    set <ll> appears;
    vl values;

    cin >> n >> x;

    for (ll i = 0; i < n; i++) {

        cin >> a;
        appears.insert(a);
        values.pb(a);

    }

    for (ll i = 0; i < n; i++) {

        for (ll j = i + 1; j < n; j++) {

            if (appears.count(x - (values[i] + values[j]))) {

                for (ll k = j + 1; k < n; k++) {

                    if (values[k] == x - (values[i] + values[j])) {

                        cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                        return;

                    }

                }

            }

        }

    }

    cout << "IMPOSSIBLE\n";
    
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