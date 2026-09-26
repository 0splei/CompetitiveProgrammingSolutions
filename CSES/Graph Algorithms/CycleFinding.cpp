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
 
struct aristas {

	ll u, v, cos;

};
 
vector <aristas> values;
ll n, m, a, b, c, dist[2505], parent[2505];
bool visitado[2505];
 
void BellFord (ll ini){
 
	dist[ini] = 0;
	ll maxi = -1, ultimo = -1;
 
	for (ll i = 0; i < n; i++){
        
		for (auto j : values){
 
			ll x = j.u, y = j.v, z = j.cos;
 
			if (dist[x] + z < dist[y]) {

				dist[y] = dist[x] + z;
				parent[y] = x;
				maxi = i;
 
				ultimo = y;
			
            }
 
		}
		
	}
 
	if (maxi != n - 1) {

		cout << "NO\n";
		return;
	
    }
 
	cout << "YES\n";
 
	vl ciclo;
	ll pos = ultimo;
 
	while (true){

		if (visitado[pos]) break;
		
        visitado[pos] = true;
		ciclo.pb(pos);
		pos = parent[pos];
	
    }

	ciclo.pb(pos);
 
	memset(visitado, false, sizeof visitado);
 
	for (ll i = ciclo.size() - 1; i >= 0; i--){
		
        cout << ciclo[i] << " ";
		if(visitado[ciclo[i]]) break;
		visitado[ciclo[i]] = true;
	
    }
 
	cout << "\n";
}
 
void SOLVE(){
 
	memset(visitado, false, sizeof visitado);
	memset(dist, ll(LLONG_MAX / 4LL), sizeof dist);
 
	cin >> n >> m;
 
	for (ll i=0; i<m; i++){

        cin >> a >> b >> c;
		values.pb({a, b, c});

    }
 
	BellFord(1);

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