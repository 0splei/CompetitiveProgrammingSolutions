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
    queue <ll> kids;

    cin >> n;

    for (ll i = 1; i <= n; i++) kids.push(i);

    while (!kids.empty()) {

        kids.push(kids.front());
        kids.pop();
        cout << kids.front() << " ";
        kids.pop();

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