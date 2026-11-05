#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second 

typedef vector<int> vi;
typedef long long ll; 

void solve(){

    ll n, x, maxi = 0, ans = 0;

    cin >> n;

    for (ll i = 0; i < n; i++) {

        cin >> x;
        if (x > maxi) {

            maxi = x;
            ans++;

        }

    }

    cout << ans << "\n";

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    solve();
}