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

    string p, b;
    map <char, ll> aparece;

    cin >> p >> b;

    for (ll i = 0; i < p.size(); i++) {

        aparece[p[i]] = i;

    }

    ll cnt = 1, voy = -1;

    for (ll i = 0; i < b.size(); i++){

        if (voy >= aparece[b[i]]) {
            
            cnt++;
            
        } 
        
        voy = aparece[b[i]];

    }

    cout << cnt << "\n";

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