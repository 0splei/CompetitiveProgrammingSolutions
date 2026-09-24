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

ll n, m;
LL start, finish, direction[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char board[1005][1005];
bool seen[1005][1005];
map <LL, LL> parent; 
vector <char> path;

bool bfs () {

    queue <LL> position;

    position.push(start);
    seen[start.F][start.S] = true;

    while(!position.empty()) {

        LL act = position.front();
        position.pop();

        for (auto i : direction) {

            ll a = act.F + i.F, b = act.S + i.S;

            if (seen[a][b] == true || board[a][b] == '#' || a >= n || a < 0 || b >= m || b < 0) continue;

            seen[a][b] = true;
            parent[{a, b}] = {act.F, act.S};
            position.push({a, b});

        }

    }

    return seen[finish.F][finish.S];

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < m; j++) {

            cin >> board[i][j];

            if (board[i][j] == 'A') start = {i, j};
            else if (board[i][j] == 'B') finish = {i, j};

        }

    }

    memset(seen, false, sizeof(seen));
    
    if (bfs() == false) {

        cout << "NO\n";
        return;
        
    }

    LL act = finish;

    while (act != start) {

        if (parent[act].F > act.F) path.pb('U');
        if (parent[act].F < act.F) path.pb('D');
        if (parent[act].S > act.S) path.pb('L');
        if (parent[act].S < act.S) path.pb('R');

        act = parent[act];

    }

    cout << "YES\n";
    cout << path.size() << "\n";
    for (ll i = path.size() - 1; i >= 0; i--) cout << path[i];
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
  return 0;
}