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

struct Node {
    
    ll x, w;
    
    bool operator < (Node a) const {
        
        return w > a.w;
        
    }
    
};

ll n, m, k, a, b, c, seen[(ll) (1e5 + 5)];
vector <Node> graph[(ll) (1e5 + 5)];
vl ans;
priority_queue <Node> pq;

void dijkstra () {

    pq.push({1, 0});

    while (!pq.empty()) {

        Node act = pq.top();
        pq.pop();
        
        seen[act.x]++;
        if (seen[act.x] > k) continue;
        
        if (act.x == n) {

            ans.pb(act.w);

            if (ans.size() == k) return;
            
        }

        for (auto i : graph[act.x]) {

            pq.push({i.x, i.w + act.w});

        }
            
    }

}

void SOLVE(){

    cin >> n >> m >> k;

    for (ll i = 0; i < m; i++) {

        cin >> a >> b >> c;
        graph[a].pb({b, c});

    }

    memset(seen, 0, sizeof(seen));

    dijkstra();

    for (auto i : ans) cout << i << " ";

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