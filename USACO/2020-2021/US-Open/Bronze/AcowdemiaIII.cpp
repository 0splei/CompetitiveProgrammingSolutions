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
    
    ll n, m, ans = 0;
    char board[1005][1005];
    set < pair <LL, LL> > pairs;
    memset(board, '.', sizeof(board));

    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {

        for (ll j = 1; j <= m; j++) {
        
            cin >> board[i][j];
        
        }
    
    }

    for (ll i = 1; i <= n; i++) {

        for (ll j = 1; j <= m; j++) {

            vll cows;

            if (board[i][j] == 'G') {

                if (board[i - 1][j] == 'C') cows.pb({i - 1, j});
                if (board[i + 1][j] == 'C') cows.pb({i + 1, j});
                if (board[i][j - 1] == 'C') cows.pb({i, j - 1});
                if (board[i][j + 1] == 'C') cows.pb({i, j + 1});

            }

            if (cows.size() > 2) ans++;
            else if (cows.size() == 2) pairs.insert({min(cows[0], cows[1]), max(cows[0], cows[1])});

        }

    }

    cout << ans + pairs.size() << "\n";

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