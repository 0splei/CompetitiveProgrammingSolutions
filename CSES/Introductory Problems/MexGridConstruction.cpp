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

ll n, board[105][105];

ll check (ll i, ll j) {

    set <ll> appears;

    ll y = i, x = j;

    while (y--) appears.insert(board[y][j]);

    while (x--) appears.insert(board[i][x]);

    for (ll k = 0; k < (n + 5) * (n + 5); k++) if (!appears.count(k)) return k;

}

void SOLVE(){

    cin >> n;

    for (ll i = 0; i < n; i++) {

        board[0][i] = i;
        board[i][0] = i;
        board[i][i] = 0;

    }

    for (ll i = 1; i < n; i++) {

        for (ll j = i + 1; j < n; j++) {

            board[i][j] = check(i, j);
            board[j][i] = board[i][j];

        }

    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) cout << board[i][j] << " ";
        cout << "\n";
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