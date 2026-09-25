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

    bool operator < (node a) const {

        return c > a.c;

    }

};

priority_queue <node> pq;
vector <node> graph[ll (1e5 + 5)];
ll seen[ll (1e5 + 5)];

void dijkstra (ll pos) {

    node start = {pos, 0};
    pq.push(start);
    
    while (!pq.empty()) {

        node act = pq.top();
        pq.pop();

        if (seen[act.x] != -1) continue;
        
        seen[act.x] = act.c;

        for (auto i : graph[act.x]) {

            if (seen[i.x] == -1) {

                pq.push({i.x, i.c + act.c});

            }

        }
            
    }

}

void SOLVE(){

    ll n, m, a, b, c;

    cin >> n >> m;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b >> c;
        graph[a].pb({b, c});

    }

    memset(seen, -1, sizeof(seen));
    dijkstra(1);

    for (ll i = 1; i <= n; i++) cout << seen[i] << " ";

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