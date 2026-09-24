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

const ll INF = 1e18;
ll n, m, monster[1005][1005], distA[1005][1005];
char board[1005][1005], parentDir[1005][1005], moveChar[4] = {'R', 'L', 'D', 'U'};
LL start, finish, dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool border(ll x, ll y) {

    return (x == 0 || x == n - 1 || y == 0 || y == m - 1);

}

void bfsMonsters(queue<LL> &q) {

    while (!q.empty()) {

        LL act = q.front();
        q.pop();

        for (ll d = 0; d < 4; d++) {

            ll x = act.F + dir[d].F, y = act.S + dir[d].S;

            if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '#') continue;

            if (monster[x][y] > monster[act.F][act.S] + 1) {

                monster[x][y] = monster[act.F][act.S] + 1;
                q.push({x, y});

            }

        }

    }

}

bool bfsA() {

    queue<LL> q;

    q.push(start);
    distA[start.F][start.S] = 0;

    if (border(start.F, start.S)) {

        finish = start;
        return true;

    }

    while (!q.empty()) {

        LL act = q.front();
        q.pop();

        for (ll d = 0; d < 4; d++) {

            ll x = act.F + dir[d].F;
            ll y = act.S + dir[d].S;

            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (board[x][y] == '#') continue;
            if (distA[x][y] != INF) continue;

            ll nextDist = distA[act.F][act.S] + 1;

            if (nextDist >= monster[x][y]) continue;

            distA[x][y] = nextDist;
            parentDir[x][y] = moveChar[d];

            q.push({x, y});

            if (border(x, y)) {

                finish = {x, y};
                return true;

            }

        }

    }

    return false;

}

void SOLVE() {

    cin >> n >> m;

    queue<LL> monstersQueue;

    for (ll i = 0; i < n; i++) {

        for (ll j = 0; j < m; j++) {

            cin >> board[i][j];

            monster[i][j] = INF;
            distA[i][j] = INF;

            if (board[i][j] == 'A') {
                start = {i, j};
            }

            if (board[i][j] == 'M') {

                monster[i][j] = 0;
                monstersQueue.push({i, j});

            }

        }

    }

    bfsMonsters(monstersQueue);

    if (!bfsA()) {

        cout << "NO\n";
        return;

    }

    vector <char> path;

    LL act = finish;

    while (act != start) {

        char d = parentDir[act.F][act.S];

        path.pb(d);

        if (d == 'R') act.S--;
        else if (d == 'L') act.S++;
        else if (d == 'D') act.F--;
        else if (d == 'U') act.F++;

    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    for (char i : path) cout << i;
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