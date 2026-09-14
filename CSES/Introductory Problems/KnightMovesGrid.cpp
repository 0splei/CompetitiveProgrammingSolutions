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

ll n, board[1005][1005];

void movement () {

    queue < pair <LL, ll> > position;
    position.push({{0, 0}, 0});

    while (!position.empty()) {

        pair <LL, ll> act = position.front();
        position.pop();

        if (board[act.F.F][act.F.S] != -1) continue;

        board[act.F.F][act.F.S] = act.S;

        if (act.F.F - 1 >= 0 && act.F.S + 2 < n) position.push({{act.F.F - 1, act.F.S + 2}, act.S + 1});
        if (act.F.F - 1 >= 0 && act.F.S - 2 >= 0) position.push({{act.F.F - 1, act.F.S - 2}, act.S + 1});
        if (act.F.F + 1 < n && act.F.S + 2 < n) position.push({{act.F.F + 1, act.F.S + 2}, act.S + 1});
        if (act.F.F + 1 < n && act.F.S - 2 >= 0) position.push({{act.F.F + 1, act.F.S - 2}, act.S + 1});

        if (act.F.F + 2 < n && act.F.S - 1 >= 0) position.push({{act.F.F + 2, act.F.S - 1}, act.S + 1});
        if (act.F.F - 2 >= 0 && act.F.S - 1 >= 0) position.push({{act.F.F - 2, act.F.S - 1}, act.S + 1});
        if (act.F.F + 2 < n && act.F.S + 1 < n) position.push({{act.F.F + 2, act.F.S + 1}, act.S + 1});
        if (act.F.F - 2 >= 0 && act.F.S + 1 < n) position.push({{act.F.F - 2, act.F.S + 1}, act.S + 1});

    }

}

void SOLVE(){

    cin >> n;

    memset(board, -1, sizeof(board));

    movement();
    
    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < n; j++) {

            cout << board[i][j] << " ";

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