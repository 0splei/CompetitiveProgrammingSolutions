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

string p;
ll ans = 0;
LL dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[9][9] = {false};

void dfs (ll x, ll y, ll cnt) {

    if (visited[x][y] == true) return;

    if (x == 1 && y == 7) {

        if (cnt == 48) ans++;
        return;

    } 

    if (cnt == 48) return;

    bool up = visited[x][y - 1], down = visited[x][y + 1], left = visited[x - 1][y], right = visited[x + 1][y];
    
    if ((left && right && !up && !down) || (up && down && !left && !right)) return;
    
    visited[x][y] = true;

    if (p[cnt] != '?') {

        if (p[cnt] == 'U') dfs (x, y - 1, cnt + 1);
        else if (p[cnt] == 'D') dfs (x, y + 1, cnt + 1);
        else if (p[cnt] == 'L') dfs (x - 1, y, cnt + 1);
        else dfs (x + 1, y, cnt + 1);

    } else {

        for (auto i : dir) {
    
            dfs(x + i.F, y + i.S, cnt + 1);
        
        }

    }

    
    visited[x][y] = false;

}

void SOLVE(){

    cin >> p;


    for (ll i = 0; i < 9; i++) {

        visited[i][0] = true;
        visited[0][i] = true;
        visited[i][8] = true;
        visited[8][i] = true;

    }

    dfs (1, 1, 0);

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