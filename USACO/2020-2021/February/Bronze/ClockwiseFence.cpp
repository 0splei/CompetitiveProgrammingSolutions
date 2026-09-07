#include <iostream>
#include <string>
#include <utility>
#include <vector>

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

    string p;
    ll x = 0, y = 0, area = 0;

    cin >> p;

    for (char c : p) {

        ll nx = x, ny = y;

        if (c == 'N') ny++;
        else if (c == 'S') ny--;
        else if (c == 'E') nx++;
        else nx--;

        area += x * ny - nx * y;
        x = nx, y = ny;

    }

    if (area < 0) cout << "CW\n";
    else cout << "CCW\n";

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