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

const ll MAXN = 1e5 + 5;
ll ST[4 * MAXN];

void update(ll left, ll right, ll node, ll l, ll r, ll val) {

    if (right < l || left > r) return;

    if (l <= left && right <= r) {

        ST[node] += val;
        return;

    }

    ll mid = (left + right) / 2;

    update(left, mid, node * 2 + 1, l, r, val);
    update(mid + 1, right, node * 2 + 2, l, r, val);

}

ll query(ll left, ll right, ll node, ll pos) {

    if (left == right) return ST[node];

    ll mid = (left + right) / 2;

    if (pos <= mid) return ST[node] + query(left, mid, node * 2 + 1, pos);

    return ST[node] + query(mid + 1, right, node * 2 + 2, pos);

}

void SOLVE() {

    ll n, q;
    cin >> n >> q;

    vl goal(n + 1);

    for (ll i = 1; i <= n; i++) cin >> goal[i];

    vl graph[ll (n + 5)];
    vector <bool> isChild(n + 1, false);

    for (ll i = 0; i < n - 1; i++) {

        ll u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        isChild[v] = 1;
    
    }

    ll root;

    for (ll i = 1; i <= n; i++) {

        if (isChild[i] == false) {
    
            root = i;
            break;
    
        }
    
    }

    vl entryTime(n + 1), exitTime(n + 1), subtreeSize(n + 1), nextChildIndex(n + 1), dfsStack = {root};
    ll currentTime = 0;

    while (!dfsStack.empty()) {

        ll currentNode = dfsStack.back();

        if (entryTime[currentNode] == 0) entryTime[currentNode] = ++currentTime;

        if (nextChildIndex[currentNode] < (ll)graph[currentNode].size()) {

            ll child = graph[currentNode][nextChildIndex[currentNode]++];
            dfsStack.pb(child);

        } else {

            exitTime[currentNode] = currentTime;
            subtreeSize[currentNode] = exitTime[currentNode] - entryTime[currentNode] + 1;

            dfsStack.pop_back();

        }
        
    }
    
    vll bonuses(q + 1);

    for (ll i = 1; i <= q; i++) cin >> bonuses[i].first >> bonuses[i].second;

    vl leftBound(n + 1, 1), rightBound(n + 1, q + 1);

    vector<vl> employeesAtMid(q + 1);

    while (true) {

        bool hasPendingSearches = false;

        for (ll j = 1; j <= q; j++) employeesAtMid[j].clear();

        for (ll employee = 1; employee <= n; employee++) {

            if (leftBound[employee] < rightBound[employee]) {

                hasPendingSearches = true;

                ll mid = (leftBound[employee] + rightBound[employee]) / 2;

                employeesAtMid[mid].push_back(employee);

            }
        }

        if (!hasPendingSearches) break;

        fill(ST, ST + 4 * MAXN, 0LL);

        for (ll bonusIndex = 1; bonusIndex <= q; bonusIndex++) {

            auto [receiver, amount] = bonuses[bonusIndex];

            ll amountPerEmployee = amount / subtreeSize[receiver];
            ll remainder = amount % subtreeSize[receiver];

            update(1, n, 0, entryTime[receiver], exitTime[receiver], amountPerEmployee);

            update(1, n, 0, entryTime[receiver], entryTime[receiver], remainder);

            for (ll employee : employeesAtMid[bonusIndex]) {

                ll totalReceived = query(1, n, 0, entryTime[employee]);

                if (totalReceived >= goal[employee]) rightBound[employee] = bonusIndex;
                else leftBound[employee] = bonusIndex + 1;

            }

        }

    }

    for (ll employee = 1; employee <= n; employee++) {

        if (leftBound[employee] == q + 1) cout << -1 << '\n';
        else cout << leftBound[employee] << '\n';

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