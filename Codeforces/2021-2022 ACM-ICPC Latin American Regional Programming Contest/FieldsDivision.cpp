#include<bits/stdc++.h>
#include <climits>
using namespace std;


typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> vvi; 

int n, m;
bool color[(ll) (3 * 1e5 + 5)]; 
vector <ll> graph[(ll) (3 * 1e5 + 5)];

void dfs (ll node) {

    if (node == n) return;

    if (color[node] == true) return;

    color[node] = true;

    for (auto i : graph[node]) dfs(i);

}

void solve(){

    cin >> n >> m; 
    
    vi ans(n + 1, 0); 
    int u,v; 
    for (int i = 0; i < m; i++){
        cin >> u >> v; 
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    memset(color, false, sizeof(color));
    dfs(n - 1);

    for (int i = 1; i <= n; i++){
        cout << ((color[i] == true) ? "B" : "A"); 
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false); 

    solve(); 
}