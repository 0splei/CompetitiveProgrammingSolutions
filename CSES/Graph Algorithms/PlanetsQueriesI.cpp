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

ll n, q, x, k, lift[(ll) (2 * 1e5 + 5)][35];

void SOLVE(){

    cin >> n >> q;

    for (ll i = 1; i <= n; i++) {

        cin >> lift[i][0];

    }

    for (ll i = 1; i < 35; i++) {

        for (ll j = 1; j <= n; j++) {

            lift[j][i] = lift[lift[j][i - 1]][i - 1];

        }

    }

    while (q--) {

        cin >> x >> k;

        for (ll j = 0; j < 35; j++) {

            if (k & (1LL << j)) x = lift[x][j];

        }

        cout << x << "\n";

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