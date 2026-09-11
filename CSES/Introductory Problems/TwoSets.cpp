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

    ll n, totalSum;

    cin >> n;
    totalSum = (n * (n + 1)) / 2;

    if (totalSum & 1) {

        cout << "NO\n";
        return;

    }

    ll actSum = 0;
    set <ll> appears;

    for (ll i = n; i >= 1; i--) {

        if (actSum + i <= totalSum / 2) {

            actSum += i;
            appears.insert(i);
        
        }

    }

    cout << "YES\n";
    cout << appears.size() << "\n";
    for (auto i : appears) cout << i << " ";
    cout << "\n";
    cout << n - appears.size() << "\n";
    for (ll i = 1; i <= n; i++) if (!appears.count(i)) cout << i << " ";

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