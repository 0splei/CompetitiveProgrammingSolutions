#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii; 
typedef vector<vii> wgraf;
typedef pair<int,ii> edge;
typedef vector <ll> vl;
typedef pair <ll, ll> LL;
typedef vector <LL> vll;
 
#define UNVISITED 0
#define VISITED 1
#define pb push_back
#define F first
#define S second
 
void SOLVE(){
    
    ll n, k, x;
    vl values;
    
    cin >> n >> k;
    
    for (ll i=0; i<n; i++) {
    
        cin >> x;
        values.pb(x);
    
    }
    
    sort (values.begin(), values.end());
    
    ll izq=0, der=values[0]*k, piv, cont;
 
    while (izq+1<der){
    
        piv=(izq+der)/2;
        cont=0;
    
        for (ll i=0; i<n; i++) cont+=piv/values[i];
    
        if (cont>=k) der=piv;
        else izq=piv;
  
    }
 
    piv=izq;
    cont=0;
  
    for (ll i=0; i<n; i++) cont+=piv/values[i];
  
    if (cont>=k) cout << izq;
    else cout << der;

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