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
    
    ll pos, weight;
    
    bool operator < (node a) const {
        
        return weight > a.weight;
        
    }
    
};

priority_queue <node> pq;
vll graph[(ll) (1e5 + 5)];
ll n, m, p, g, u, v, d, dist[(ll) (1e5 + 5)], distNoG[(ll) (1e5 + 5)];
set <ll> candidates;

void dijkstra () {

    pq.push({p, 0});

    while (!pq.empty()) {

        node act = pq.top();
        pq.pop();

        if (dist[act.pos] != -1) continue;

        dist[act.pos] = act.weight;
        if (dist[g] != -1 && dist[act.pos] == dist[g] * 2) candidates.insert(act.pos);

        for (auto i : graph[act.pos]) {

            if (dist[i.F] == -1) pq.push({i.F, act.weight + i.S});

        }

    }

}

void dijkstraNoG () {

    pq.push({p, 0});

    while (!pq.empty()) {

        node act = pq.top();
        pq.pop();

        if (distNoG[act.pos] != -1 || act.pos == g) continue;

        distNoG[act.pos] = act.weight;

        for (auto i : graph[act.pos]) {

            if (distNoG[i.F] == -1 && i.F != g) pq.push({i.F, act.weight + i.S});

        }

    }

}

void SOLVE(){

    cin >> n >> m >> p >> g;

    for (ll i = 0; i < m; i++) {

        cin >> u >> v >> d;

        graph[u].pb({v, d});
        graph[v].pb({u, d});

    }

    memset(dist, -1, sizeof (dist));
    memset(distNoG, -1, sizeof (distNoG));

    dijkstra();
    dijkstraNoG();

    bool can = false;

    for (auto i : candidates) {

        if (dist[i] < distNoG[i] || distNoG[i] == -1) {

            cout << i << " ";
            can = true;

        }

    }

    if (can == false) cout << "*\n";

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