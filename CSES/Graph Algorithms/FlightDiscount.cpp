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

struct node {

    ll x, c;
    bool used;

    bool operator < (node a) const {

        return c > a.c;

    }

};

ll n, m, a, b, c;
priority_queue <node> pq;
vector <LL> graph[(ll) (1e5 + 5)];
ll seen[(ll) (1e5 + 5)][2];

void dijkstra (ll start) {

    pq.push({start, 0});

    while (!pq.empty()) {

        node act = pq.top();
        pq.pop();

        if (act.used == false) {

            if (seen[act.x][0] == -1) {
        
                seen[act.x][0] = act.c;

                for (auto i : graph[act.x]) {

                    if (seen[i.F][0] == -1) {

                        pq.push({i.F, i.S + act.c, false});

                    }

                    if (seen[i.F][1] == -1) {

                        pq.push({i.F, (i.S / 2) + act.c, true});
                    
                    }

                }

            }

        } else {

            if (seen[act.x][1] == -1) {
        
                seen[act.x][1] = act.c;

                for (auto i : graph[act.x]) {

                    if (seen[i.F][1] == -1) {

                        pq.push({i.F, i.S + act.c, true});

                    }

                }

            }

        }

    }

}

void SOLVE(){

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b >> c;
        graph[a].pb({b, c});

    }

    memset(seen, -1, sizeof(seen));
    dijkstra(1);

    cout << seen[n][1] << "\n";

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