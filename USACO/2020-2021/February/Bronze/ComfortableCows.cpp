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

pair <bool, int> hay[1005][1005];

void SOLVE(){

    ll n, x, y, ans = 0;
    
    memset(hay, 0, sizeof(hay));

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x >> y;

        hay[x][y] = {true, hay[x][y].S};

        if (hay[x][y].S == 3) ans++;

        if (x > 0) hay[x - 1][y].S++;
        hay[x + 1][y].S++;
        if (y > 0) hay[x][y - 1].S++;
        hay[x][y + 1].S++;

        if (x > 0 && hay[x - 1][y].F == true) { 
            
            if (hay[x - 1][y].S == 3) ans++;
            else if (hay[x - 1][y].S == 4) ans--;

        }
        
        if (hay[x + 1][y].F == true) { 
            
            if (hay[x + 1][y].S == 3) ans++;
            else if (hay[x + 1][y].S == 4) ans--;

        }

        if (y > 0 && hay[x][y - 1].F == true) { 
            
            if (hay[x][y - 1].S == 3) ans++;
            else if (hay[x][y - 1].S == 4) ans--;

        }

        if (hay[x][y + 1].F == true) { 
            
            if (hay[x][y + 1].S == 3) ans++;
            else if (hay[x][y + 1].S == 4) ans--;

        }

        cout << ans << "\n";

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
  return 0;
}