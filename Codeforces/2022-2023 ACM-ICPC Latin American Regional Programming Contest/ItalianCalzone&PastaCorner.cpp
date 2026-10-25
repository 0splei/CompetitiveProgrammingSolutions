#include <bits/stdc++.h>
#include <queue>
 
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

ll matriz[105][105];
ll r, c;

map <ll, LL> posiciones;

void SOLVE(){

  cin >> r >> c;

  for (ll i = 0; i < r; i++){
    for (ll j = 0; j < c; j++) {
      cin >> matriz[i][j];
      posiciones[matriz[i][j]] = {i, j};
    }
  }

  ll maxi = 0, ans = 0, cnt;
  set <ll> vistos;

  for (ll i = 1; i <= r * c; i++) {
    maxi = 0;
    cnt = 0;
    priority_queue<ll> disponibles;

    disponibles.push(-i);

    if (vistos.count(i) == 0) {
      while (disponibles.size()) {
        ll act = -disponibles.top();
        disponibles.pop();

        if (maxi < act) {

          vistos.insert(act);

          cnt++;
          maxi = act;

          if (posiciones[act].F + 1 < r) disponibles.push(-matriz[posiciones[act].F + 1][posiciones[act].S]);
          if (posiciones[act].F - 1 >= 0) disponibles.push(-matriz[posiciones[act].F - 1][posiciones[act].S]);
          if (posiciones[act].S + 1 < c) disponibles.push(-matriz[posiciones[act].F][posiciones[act].S + 1]);
          if (posiciones[act].S - 1 >= 0) disponibles.push(-matriz[posiciones[act].F][posiciones[act].S - 1]);

        }
      }
    }

    ans = max(ans, cnt);
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