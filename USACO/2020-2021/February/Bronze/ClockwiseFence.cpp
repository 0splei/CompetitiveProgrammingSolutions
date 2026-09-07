#include <iostream>
#include <string>
#include <utility>
#include <vector>

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
    bool right = false, left = false, up = false, down = false;

    cin >> p;

    if (p[0] == 'W') left = true;
    else if (p[0] == 'E') right = true;
    else if (p[0] == 'N') up = true;
    else down = true;

    if (left == true) {

        for (ll i = 0; i < p.size(); i++) {

            if (p[i] == 'N') {

                cout << "CW\n";
                return;

            } else if (p[i] == 'S') {

                cout << "CCW\n";
                return;

            }

        }

    } else if (right == true) {

        for (ll i = 0; i < p.size(); i++) {

            if (p[i] == 'N') {

                cout << "CCW\n";
                return;

            } else if (p[i] == 'S') {

                cout << "CW\n";
                return;

            }

        }

    } else if (up == true) {

        for (ll i = 0; i < p.size(); i++) {

            if (p[i] == 'E') {

                cout << "CW\n";
                return;

            } else if (p[i] == 'W') {

                cout << "CCW\n";
                return;

            }

        }
        
    } else if (down == true) {

        for (ll i = 0; i < p.size(); i++) {

            if (p[i] == 'W') {

                cout << "CW\n";
                return;

            } else if (p[i] == 'E') {

                cout << "CCW\n";
                return;

            }

        }
        
    }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--){
    SOLVE();
  }
  return 0;
}