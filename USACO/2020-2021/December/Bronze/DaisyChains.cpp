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
    
    ll n, p, ans;
    vl flores;
    
    cin >> n;
    ans = n;
    
    for (ll i = 0; i < n; i++) {
        
        cin >> p;
        flores.pb(p);
        
    }
    
    for (ll i = 0; i < n; i++){
        
        set <ll> aparece;
        ll suma = flores[i];

        aparece.insert(flores[i]);
        
        for (ll j = i + 1; j < n; j++) {
        
            suma += flores[j];
            aparece.insert(flores[j]);

            if (suma % (j + 1 - i) == 0 && aparece.count(suma / (j + 1 - i))) ans++;

        }
        
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
}