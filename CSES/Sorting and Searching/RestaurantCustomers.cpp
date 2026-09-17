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

    ll n, a, b, ans = 0, act = 0;
    priority_queue <ll> arrives, leaves; 

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> a >> b;

        arrives.push(-a);
		leaves.push(-b);

    }

	ll pos = -arrives.top();
	act++;
	arrives.pop();

	while (!leaves.empty() && !arrives.empty()) {

		pos = min(-arrives.top(), -leaves.top());

		if (pos == -arrives.top()) {
		
			act++;
			arrives.pop();
		
		} else {

			act--;
			leaves.pop();

		}

		ans = max(ans, act);

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