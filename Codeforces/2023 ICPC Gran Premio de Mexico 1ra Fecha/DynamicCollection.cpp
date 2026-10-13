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

ll n, q, option, k, a, b;
vl values;
map <ll, ll> appears;

ll BS (ll obj) {

    ll izq = 0, der = values.size() - 1, mid;

    while (izq + 1 < der) {

        mid = (izq + der) / 2;

        if (values[mid] >= obj) der = mid;
        else izq = mid;

    }

    if (values[izq] >= obj) return izq;
    else return der;

}

ll BSmax (ll obj) {

    values.pb(LLONG_MAX);
    ll izq = 0, der = values.size() - 1, mid;

    while (izq + 1 < der) {

        mid = (izq + der) / 2;

        if (values[mid] > obj) der = mid;
        else izq = mid;

    }

    values.pop_back();

    if (values[izq] > obj) return izq;
    else return der;

}

void SOLVE(){

    cin >> n >> q;

    for (ll i = 0; i < n; i++) {

        cin >> a;
        values.pb(a);
        appears[a]++;

    }

    sort(values.begin(), values.end());

    while (q--) {

        cin >> option;

        if (option == 1) {

            cin >> k;

            if (appears[k] >= 1) continue;

            if (values[values.size() - 1] < k) {
                
                values.pb(k);
                appears[k]++;

            } else {

                ll pos = BSmax(k);

                appears[values[pos]]--;
                values[pos] = k;
                appears[values[pos]]++;

            }

        } else {

            cin >> a >> b;

            if (a > values[values.size() - 1] || b < values[0]) {

                cout << "0\n";
                continue;

            }

            ll der = BSmax(b), izq = BS(a);

            cout << der - izq << "\n";

        }

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