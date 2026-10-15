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
    
    ll n, k, board[1005][1005], ans = 0;
    cin >> n >> k;

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < n; j++) cin >> board[i][j];

    }

    for (ll i = 0; i <= n - k; i++) {

        for (ll j = 0; j <= n - k; j++) {

            if (board[i][j] == board[i + k - 1][j]
                && board[i][j] == board[i][j + k - 1]
                && board[i][j] == board[i + k - 1][j + k - 1]) ans++;

        }

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