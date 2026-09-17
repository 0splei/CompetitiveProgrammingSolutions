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

    ll n, a, b, ans = 1;
    priority_queue <LL> movies;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> a >> b;
        movies.push({-b, -a});

    }

    ll time = -movies.top().F;
    movies.pop();

    while (!movies.empty()) {

        if (time <= -movies.top().S) {

            time = -movies.top().F;
            ans++;

        }

        movies.pop();

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