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

void SOLVE() {

    ll n, k, dp[55][55][2][5] = {};
    cin >> n >> k;

    char board[n + 5][n + 5];

    for (ll i = 0; i < n; i++) {
    
        for (ll j = 0; j < n; j++) {
    
            cin >> board[i][j];
        
        }
    
    }

    if (n > 1 && board[0][1] != 'H') dp[0][1][0][0] = 1;

    if (n > 1 && board[1][0] != 'H') dp[1][0][1][0] = 1;

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < n; j++) {

            if (board[i][j] == 'H') continue;

            for (ll turns = 0; turns <= k; turns++) {

                if (dp[i][j][0][turns]) {

                    if (j + 1 < n && board[i][j + 1] != 'H') {

                        dp[i][j + 1][0][turns] += dp[i][j][0][turns];

                    }

                    if (i + 1 < n && board[i + 1][j] != 'H' && turns + 1 <= k) {

                        dp[i + 1][j][1][turns + 1] += dp[i][j][0][turns];

                    }

                }

                if (dp[i][j][1][turns]) {

                    if (i + 1 < n && board[i + 1][j] != 'H') {

                        dp[i + 1][j][1][turns] += dp[i][j][1][turns];

                    }

                    if (j + 1 < n && board[i][j + 1] != 'H' && turns + 1 <= k) {

                        dp[i][j + 1][0][turns + 1] += dp[i][j][1][turns];

                    }

                }

            }

        }

    }

    ll ans = 0;

    for (ll turns = 0; turns <= k; turns++) {

        ans += dp[n - 1][n - 1][0][turns];
        ans += dp[n - 1][n - 1][1][turns];

    }

    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        SOLVE();
    }
    return 0;
}