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

ll n;
string p;
vector <string> names;
map <char, ll> inDegree;
vector <char> graph['z' + 5], order;
bool posible = true;
set <char> seen;

void kahn () {

    for (ll i = 0; i < n; i++) {

        for (ll j = i + 1; j < n; j++) {

            bool connection = false;

            for (ll k = 0; k < names[i].size(); k++) {

                if (names[i][k] != names[j][k]) {

                    graph[names[i][k]].pb(names[j][k]);
                    inDegree[names[j][k]]++;
                    connection = true;
                    break;

                }

            } 

            if (connection == false && names[i].size() > names[j].size()) return;

        }

    }

    queue <char> q;

    for (char i = 'a'; i <= 'z'; i++) {

        if (inDegree[i] == 0) {

            q.push(i);

        }

    }

    while (!q.empty()) {

        char act = q.front();
        q.pop();
        order.pb(act);

        for (auto i : graph[act]) {

            inDegree[i]--;

            if (inDegree[i] == 0) {
                
                q.push(i);

            }

        }

    }

}

void SOLVE(){

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> p;
        names.pb(p);

    }

    kahn();

    if (order.size() == 26) {

        for (auto i : order) cout << i;

    } else cout << "Impossible\n";

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