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

    ll a, b, x, y;

    cin >> a >> b;
    y = (2 * b) - a;

    if (y % 3 != 0) {

        cout << "NO\n";
        return;

    }

    y /= 3;
    x = b - (2 * y);

    if (x >= 0 && y >= 0) {

        cout << "YES\n";
        return;

    }

    cout << "NO\n";

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