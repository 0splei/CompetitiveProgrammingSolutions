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

    string p;
    pair <char, ll> cnt = {'a', '0'};
    ll ans = 0;

    cin >> p;
    
    for (auto i : p) {

        if (i == cnt.F) cnt.S++;
        else cnt = {i, 1};

        ans = max(ans, cnt.S);

    }

    cout << ans << "\n";

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