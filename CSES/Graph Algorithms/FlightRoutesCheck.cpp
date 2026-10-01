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
vl ciudad[(ll) 1e5 +5][2];
bool visto[(ll) 1e5 +5];
 
void dfs (ll x, ll y) {

	if (visto[x] == true) return;
	
	visto[x] = true;
	
	for (auto i : ciudad[x][y]) dfs(i, y);

}
 
void SOLVE(){
	
	memset(visto, false, sizeof(visto));
	
	cin >> n >> m;
	
	for (ll i = 0; i < m; i++){
	
		cin >> a >> b;
	
		ciudad[a][0].pb(b);
		ciudad[b][1].pb(a);
	
	}
	
	dfs(1, 0);
	
	for (ll i = 1; i <= n; i++){

		if (visto[i] == false) {
		
			cout << "NO\n";
			cout << "1 " << i << "\n";
	
			return;
		
		}
	
	}
	
	memset(visto, false, sizeof(visto));
	
	dfs(1, 1);
	
	for (ll i = 1; i <= n; i++){
	
		if (visto[i] == false) {
	
			cout << "NO\n";
			cout << i << " 1\n";
	
			return;
		
		}
	
	}
	
	cout << "YES\n";

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