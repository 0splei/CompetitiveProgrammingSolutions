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

    string p;
    map <char, ll> appears;
    pair <char, ll> impar = {'.', 0};

    cin >> p;

    for (auto i : p) appears[i]++;

    for (auto i : appears) {

        if (i.S & 1) {

            if (impar.S != 0) {

                cout << "NO SOLUTION\n";
                return;

            } else {

                impar = i;

            }

        }

    }

    string ans = "";

    for (auto i : appears) {

        if (i.F == impar.F) continue;

        for (ll j = 0; j < i.S / 2; j++) ans += i.F;

    }

    cout << ans;
    while (impar.S--) cout << impar.F;
    reverse(ans.begin(), ans.end());
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