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

    ll y, x;

    cin >> y >> x;

    if (x > y) {
        
        ll starts = x * x;

        if (x & 1) cout << starts - (y - 1) << "\n";
        else {

            starts = (x - 1) * (x - 1);
            starts++;
            cout << starts + (y - 1) << "\n";

        }

    } else if (y > x) {

        ll starts = y * y;

        if (!(y & 1)) cout << starts - (x - 1) << "\n";
        else {

            starts = (y - 1) * (y - 1);
            starts++;
            cout << starts + (x - 1) << "\n";

        }

    } else {

        ll greatest = x * y;

        cout << greatest - (x - 1) << "\n";

    }

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