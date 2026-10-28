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

struct nodes {

    ll open, close, paired;

};

string s;
nodes ST[(ll) (4 * (1e6 + 5))];
ll m;

void build (ll left, ll right, ll node) {

    if (left == right) {

        if (s[left] == '(') ST[node] = {1, 0, 0};
        else ST[node] = {0, 1, 0};

        return;

    }

    ll mid = (left + right) / 2;

    build (left, mid, (node * 2) + 1);
    build (mid + 1, right, (node * 2) + 2);

    ll leftChild = (node * 2) + 1, rightChild = (node * 2) + 2;

    ll paired = min(ST[leftChild].open, ST[rightChild].close);

    ST[node] = {ST[leftChild].open + ST[rightChild].open - paired, ST[rightChild].close + ST[leftChild].close - paired, paired + ST[leftChild].paired + ST[rightChild].paired};

}

nodes querie (ll left, ll right, ll node, ll l, ll r) {

    if (left > r || right < l) return {0, 0, 0};

    if (left >= l && right <= r) return ST[node];

    ll mid = (left + right) / 2;
    
    nodes leftChild = querie (left, mid, (node * 2) + 1, l, r), rightChild = querie (mid + 1, right, (node * 2) + 2, l, r), parent;
    
    ll paired = min(leftChild.open, rightChild.close);

    parent = {leftChild.open + rightChild.open - paired, rightChild.close + leftChild.close - paired, rightChild.paired + leftChild.paired + paired};

    return parent;

}

void SOLVE(){

    cin >> s >> m;

    ll l, r;

    build(0, s.size() - 1, 0);

    for (ll i = 0; i < m; i++) {

        cin >> l >> r;
        l--;
        r--;

        nodes ans = querie(0, s.size() - 1, 0, l, r);

        cout << 2 * ans.paired << "\n";

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