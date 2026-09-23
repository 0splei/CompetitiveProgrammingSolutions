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

    ll n, a, b, x, ans = LLONG_MIN;
    vl total;
    map <ll, ll> appears;
    multiset <ll> starts;

    cin >> n >> a >> b;
    total.pb(0);

    for (ll i = 0; i < n; i++) {

        cin >> x;
        total.pb(total[i] + x);
    
    }

    starts.insert(0);
    appears[0]++;

    for (ll i = a; i <= n; i++) {

        if (i > b) {

            appears[total[i - b - 1]]--;
            if (appears[total[i - b - 1]] == 0) starts.erase(total[i - b - 1]);

        }

        ans = max(ans, total[i] - *starts.begin());
        starts.insert(total[i + 1 - a]);
        appears[total[i + 1 - a]]++;

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