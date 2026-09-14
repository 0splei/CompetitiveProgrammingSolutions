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

    ll n, m;
    char grid[505][505], ans[505][505];
    string row;

    cin >> n >> m;

    for (ll i = 0; i < n; i++) {

        cin >> row;

        for (ll j = 0; j < m; j++) {

            grid[i][j] = row[j];

        }

    }

    //0 = A : 1 = B : 2 = C: 3 = D

    ans[0][0] = ((grid[0][0] + 1 - 'A') % 4) + 'A';

    for (ll i = 1; i < n; i++) {
 
        if ('A' != ans[i - 1][0] && 'A' != grid[i][0]) ans[i][0] = 'A';
        else if ('B' != ans[i - 1][0] && 'B' != grid[i][0]) ans[i][0] = 'B';
        else if ('C' != ans[i - 1][0] && 'C' != grid[i][0]) ans[i][0] = 'C';
        else ans[i][0] = 'D';

    }

    for (ll i = 1; i < m; i++) {

        if ('A' != ans[0][i - 1] && 'A' != grid[0][i]) ans[0][i] = 'A';
        else if ('B' != ans[0][i - 1] && 'B' != grid[0][i]) ans[0][i] = 'B';
        else if ('C' != ans[0][i - 1] && 'C' != grid[0][i]) ans[0][i] = 'C';
        else ans[0][i] = 'D';

    }

    for (ll i = 1; i < n; i++) {

        for (ll j = 1; j < m; j++) {

            if ('A' != ans[i - 1][j] && 'A' != ans[i][j - 1] && 'A' != grid[i][j]) ans[i][j] = 'A';
            else if ('B' != ans[i - 1][j] && 'B' != ans[i][j - 1] && 'B' != grid[i][j]) ans[i][j] = 'B';
            else if ('C' != ans[i - 1][j] && 'C' != ans[i][j - 1] && 'C' != grid[i][j]) ans[i][j] = 'C';
            else ans[i][j] = 'D';

        }

    }

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < m; j++) {

            cout << ans[i][j];

        }

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