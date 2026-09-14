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

vll moves;

void hanoi (ll n, ll a, ll b, ll c) {

    if (n == 1) {
        
        moves.pb({a, c});
        return;

    }

    hanoi(n - 1, a, c, b);

    moves.pb({a, c});

    hanoi(n - 1, b, a, c);

}

void SOLVE(){

    ll n;

    cin >> n;

    hanoi(n, 1, 2, 3);

    cout << moves.size() << "\n";

    for (auto i : moves) cout << i.F << " " << i.S << "\n";

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