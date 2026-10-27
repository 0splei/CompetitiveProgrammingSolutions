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

void SOLVE(){

    ll n, k, v, last = -1, ans = 1;

    cin >> n;
    vl graph[n + 5];
    map <ll, ll> inDegree;

    for (ll i = 0; i < n; i++) {

        cin >> k;

        while (k--) {

            cin >> v;
            v--;
            graph[v].pb(i);
            inDegree[i]++;

        }

    }

    set <ll> kahn;

    for (ll i = 0; i < n; i++) {

        if (inDegree[i] == 0) kahn.insert(i);

    }

    ll seen = 0;

    while (!kahn.empty()) {

        ll act;

        if (kahn.upper_bound(last) == kahn.end()) act = *kahn.begin();
        else act = *kahn.upper_bound(last);

        kahn.erase(act);

        if (act < last) ans++;
        last = act;
        seen++;

        for (auto i : graph[act]) {

            inDegree[i]--;

            if (inDegree[i] == 0) kahn.insert(i);

        }

    }

    if (seen != n) {

        cout << "-1\n";
        return;

    }

    cout << ans << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--){
    SOLVE();
  }
  return 0;
}