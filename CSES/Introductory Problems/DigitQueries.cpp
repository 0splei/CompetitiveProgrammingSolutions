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

    ll k, digits = 1, count = 9, start = 1, number, position;
    string ans;

    cin >> k;

    while (k > count * digits) {

        k -= count * digits;
        digits++;
        count *= 10;
        start *= 10;

    }

    k--;
    number = start + k / digits;
    position = k % digits;
    ans = to_string(number);

    cout << ans[position] << "\n";

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