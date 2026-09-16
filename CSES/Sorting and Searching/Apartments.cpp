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
    
    ll n, m, k, x;
    vl people, apartment;

    cin >> n >> m >> k;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        people.pb(x);

    }

    for (ll i = 0; i < m; i++) {

        cin >> x;
        apartment.pb(x);

    }

    sort(people.begin(), people.end());
    sort(apartment.begin(), apartment.end());
    ll ans = 0, posPeople = 0, posApartment = 0;

    while (posPeople < n && posApartment < m) {

        ll difference = people[posPeople] - apartment[posApartment];

        if (abs(difference) <= k) {

            posPeople++;
            posApartment++;
            ans++;

        } else if (difference > 0) posApartment++;
        else posPeople++;

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