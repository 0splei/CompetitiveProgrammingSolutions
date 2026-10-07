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

    ll pos, weight, ways, minTravel, maxTravel;

    bool operator < (node a) const {

        return weight > a.weight;

    }

};

priority_queue <node> pq;
vll graph[(ll) (1e5 + 5)];
ll n, m, a, b, c, mod = 1e9 + 7;
node seen[(ll) (1e5 + 5)];

void dijkstra() {

    seen[1] = {1, 0, 1, 0, 0};

    pq.push({1, 0, 0, 0, 0});

    while (!pq.empty()) {

        node act = pq.top();
        pq.pop();

        if (act.weight > seen[act.pos].weight) continue;

        for (auto i : graph[act.pos]) {

            ll next = i.F;
            ll newWeight = seen[act.pos].weight + i.S;

            if (newWeight < seen[next].weight) {

                seen[next].weight = newWeight;
                seen[next].ways = seen[act.pos].ways;
                seen[next].minTravel = seen[act.pos].minTravel + 1;
                seen[next].maxTravel = seen[act.pos].maxTravel + 1;

                pq.push({next, newWeight, 0, 0, 0});

            } else if (newWeight == seen[next].weight) {

                seen[next].ways += seen[act.pos].ways;
                seen[next].ways %= mod;

                seen[next].minTravel = min(seen[next].minTravel, seen[act.pos].minTravel + 1);
                seen[next].maxTravel = max(seen[next].maxTravel, seen[act.pos].maxTravel + 1);

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

    for (ll i = 0; i <= n; i++) {

        seen[i] = {i, LLONG_MAX, 0, LLONG_MAX, 0};

    }

    dijkstra();

    cout << seen[n].weight << " " << seen[n].ways << " " << seen[n].minTravel << " " << seen[n].maxTravel << "\n";

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