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

    ll k, n;
    char board[105][105];
    string p;
    vector <string> order;
    map <string, ll> cowId;

    cin >> k >> n;

    memset(board, '?', sizeof(board));

    for (ll i = 0; i < n; i++) {

        cin >> p;
        cowId[p] = i;
        order.pb(p);
        
    }

    ll xd = 1;
    
    while (k--) {

        vector <string> current;

        for (ll i = 0; i < n; i++) {

            cin >> p;
            current.pb(p);

        }

        for (ll i = 0; i < n; i++) {

            bool inOrderLeft = true, inOrderRight = true;

            for (ll j = i - 1; j >= 0; j--) {

                if (inOrderLeft == true && current[j + 1] < current[j]) inOrderLeft = false;

                if (inOrderLeft == false) {

                    board[cowId[current[i]]][cowId[current[j]]] = '1';
                    board[cowId[current[j]]][cowId[current[i]]] = '0';

                }

            }

            for (ll j = i + 1; j < n; j++) {

                if (inOrderRight == true && current[j - 1] > current[j]) inOrderRight = false;

                if (inOrderRight == false) {

                    board[cowId[current[i]]][cowId[current[j]]] = '0';
                    board[cowId[current[j]]][cowId[current[i]]] = '1';

                }

            }

            board[cowId[current[i]]][cowId[current[i]]] = 'B';

        }

    }

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < n; j++) {

            cout << board[i][j];

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