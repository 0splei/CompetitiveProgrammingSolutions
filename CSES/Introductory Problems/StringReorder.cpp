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

    string p, ans = "";
    ll n, maxi = 0;
    char last = '.';
    map <char, ll> appears;

    cin >> p;
    n = p.size();

    for (auto i : p) {

        appears[i]++;
        maxi = max(appears[i], maxi);

    }

    if (maxi * 2 > n + 1) {

        cout << "-1\n";
        return;

    }

    for (ll i = 0; i < n; i++) {

        ll remains = n - i;
        char mandatory = '.', act = '.';

        for (char l = 'A'; l <= 'Z'; l++) {

            if (2 * appears[l] > remains) {
                
                mandatory = l;
                break;
            
            }

        }

        if (mandatory != '.') {

            if (mandatory == last) {

                cout << "-1\n";
                return;

            }

            act = mandatory;

        } else {

            for (char l = 'A'; l <= 'Z'; l++) {

                if (appears[l] == 0 || l == last) continue;

                act = l;
                break;

            }

        }

        if (act == '.') {

            cout << "-1\n";
            return;
            
        }

        ans += act;
        appears[act]--;
        last = act;

    }

    cout << ans << "\n";

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