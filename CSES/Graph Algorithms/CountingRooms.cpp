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

ll n, m, ans = 0;
LL direction [4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char board[1005][1005];
bool visto[1005][1005];

void check (ll x, ll y) {

    if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '#' || visto[x][y] == true) return;

    visto[x][y] = true;

    for (auto i : direction) check(x + i.F, y + i.S);

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < m; j++) {

            cin >> board[i][j];

        }

    }

    memset(visto, false, sizeof (visto));

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < m; j++) {

            if (board[i][j] != '#' && visto[i][j] == false) {
             
                check(i, j);
                ans++;
            
            }

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