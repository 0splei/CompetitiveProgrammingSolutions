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
 
ll n, r, p = 0, goes[(ll) (2 * 1e5) + 5], pathSize[(ll) (2 * 1e5) + 5];
bool seen[(ll) (2 * 1e5) + 5];
queue <ll> q;
 
void dfs (ll node) {
	
    q.push(node);
	
    if (seen[node] == true) {
	
        p += pathSize[node];
		return;
	
    }
 
	seen[node] = true;
    p++;
 
	dfs(goes[node]);
    
}
 
void SOLVE() {
  
    memset(seen, false, sizeof(seen));
 
	cin >> n;
 
	for (ll i = 1; i <= n; i++) cin >> goes[i];
 
	for (ll i = 1; i <= n; i++) {
		
        if (seen[i] == false) {
		    
            p = 0;
			dfs(i);
			r = 1;
 
			while (!q.empty()) {
 
				if (q.front() == q.back()) r = 0;
				pathSize[q.front()] = p;
				p -= r;
				q.pop();
 
			}
 
		}
 
	}
 
	for (ll i = 1; i <= n; i++) cout << pathSize[i] << " ";
	cout << "\n";

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