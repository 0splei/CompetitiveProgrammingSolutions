#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 

typedef long long ll; 
typedef vector<int> vi; 

void solve(){
    
    ll n, g;
    string p, resp;
    vector <string> appears;
    set <char> letters;

    cin >> n;
    
    for (ll i = 0; i < n; i++) {

        cin >> p;
        appears.push_back(p);

    }

    resp = appears[0];

    for (auto i : resp) letters.insert(i);

    cin >> g;

    while (g--) {

        cin >> p;
        ll ans = 0;

        for (ll i = 0; i < n; i++) {

            string act = appears[i];
            bool can = true;

            for (ll j = 0; j < p.size(); j++) {

                if (p[j] == 'X') {

                    if (act[j] == resp[j] || letters.count(act[j]) >= 1) can = false;

                } else if (p[j] == '!') {

                    if (act[j] == resp[j] || letters.count(act[j]) == 0) can = false;

                } else {

                    if (act[j] != resp[j]) can = false;

                }

            }

            if (can) ans++;

        }

        cout << ans << "\n";
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 

    solve(); 
}