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

    ll n, act = 1, sums = 2;
    bool start = true;

    cin >> n;

    while (n > act) {

        act += sums;

        if (start == false) {

            start = true;
            sums++;

        } else start = false;

    }

    if (start == true) {

        cout << "Jane\n";

    } else {

        cout << "John\n";

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