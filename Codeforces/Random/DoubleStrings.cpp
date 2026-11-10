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

    ll n;
    string p;
    map <string, bool> appears;
    vector <string> values;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> p;
        values.pb(p);
        appears[p] = true;

    }

    for (auto i : values) {

        string p1 = "", p2;
        bool can = false;

        for (ll j = 0; j < i.size() - 1; j++) {

            p2 = "";
            p1 += i[j];

            for (ll k = j + 1; k < i.size(); k++) p2 += i[k];

            if (appears[p1] && appears[p2]) {

                can = true;
                cout << 1;
                break;

            } 

        }

        if (!can) cout << 0;

    }

    cout << "\n";

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