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
 
ll n, m, a, b;
vl grafo[100005], ciclo;
bool visto[100005], llevo[100005];
 
bool dfs(ll nodo){
 
  visto[nodo] = llevo[nodo] = true;
 
  for (auto i:grafo[nodo]){
 
    if (llevo[i]){
 
      ciclo.pb(nodo);
      llevo[nodo] = llevo[i] = false;
      return true;
 
    } else if (!visto[i]){
 
      if (dfs(i)) {
 
        if (llevo[nodo]) {
 
          ciclo.pb(nodo);
          llevo[nodo]=false;
          return true;
 
        } else {
 
          ciclo.pb(nodo);
          return false;
 
        }
 
      }
 
      if (!ciclo.empty()) return false;
 
    }
 
  }
 
  llevo[nodo]=false;
  return false;
 
}
 
void SOLVE(){
  cin >> n >> m;
 
  for (ll i=0; i<m; i++){
    cin >> a >> b;
    grafo[a].pb(b);
  }
 
  for (ll i=1; ciclo.empty() && i<=n; i++) dfs(i);
 
  if (ciclo.empty()) cout << "IMPOSSIBLE\n";
  else {
    reverse(ciclo.begin(), ciclo.end());
    cout << ciclo.size()+1 << "\n";
    for (auto i:ciclo) cout << i << " ";
    cout << ciclo[0] << "\n";
  }
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