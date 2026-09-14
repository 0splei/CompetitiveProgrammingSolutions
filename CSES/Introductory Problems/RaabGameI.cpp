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

    ll n, a, b;
    vl team1, team2;

    cin >> n >> a >> b;

    for (ll i = 1; i <= n; i++) {

        team1.pb(i);
        team2.pb(i);

    }

    if (a == 0 && b == 0) {

        cout << "YES\n";
        for (auto i : team1) cout << i << " ";
        cout << "\n"; 
        for (auto i : team1) cout << i << " ";
        cout << "\n";

        return;

    }

    if ((a == 0 || b == 0) || (a + b > n)) {

        cout << "NO\n";
        return;

    }

    rotate(team2.begin(), team2.begin() + a, team2.begin() + a + b);

    cout << "YES\n";
    for (auto i : team1) cout << i << " ";
    cout << "\n"; 
    for (auto i : team2) cout << i << " ";
    cout << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--){
    SOLVE();
  }
  return 0;
}