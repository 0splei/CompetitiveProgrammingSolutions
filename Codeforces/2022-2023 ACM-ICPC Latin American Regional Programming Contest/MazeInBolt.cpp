#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<int> vi; 

#define F first
#define S second 

ll r, c;
bool posible[1005][105][2], ans = false, seen[1005][105][2];
string nut, row;
ll positions[105][105][2];
pair <ll, ll> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void flfl (ll fila, ll columna) {

	if (fila > r || fila < 0 || columna >= c || columna < 0 || seen[fila][columna][0]) return;

	seen[fila][columna][0] = true;

	if (fila == r) {

		ans = true;
		return;

	}

	for (auto i : directions) {

		if (fila + i.F >= 0 && columna + i.S < 0 && posible[fila + i.F][c - 1][0]) flfl(fila + i.F, c - 1);
		else if (fila + i.F >= 0 && columna + i.S >= c && posible[fila + i.F][0][0]) flfl(fila + i.F, 0);
		else if (fila + i.F >= 0 && columna + i.S <= c && columna + i.S >= 0 && posible[fila + i.F][columna + i.S][0]) {
			
			flfl(fila + i.F, columna + i.S);

		}

	}

}

void flfl2 (ll fila, ll columna) {

	if (fila > r || fila < 0 || columna >= c || columna < 0 || seen[fila][columna][1]) return;

	seen[fila][columna][1] = true;

	if (fila == r) {

		ans = true;
		return;

	}

	for (auto i : directions) {

		if (fila + i.F >= 0 && columna + i.S < 0 && posible[fila + i.F][c - 1][1]) flfl2(fila + i.F, c - 1);
		else if (fila + i.F >= 0 && columna + i.S >= c && posible[fila + i.F][0][1]) flfl2(fila + i.F, 0);
		else if (fila + i.F >= 0 && columna + i.S <= c && columna + i.S >= 0 && posible[fila + i.F][columna + i.S][1]) {
			
			flfl2(fila + i.F, columna + i.S);

		}

	}

}

void solve(){

	cin >> r >> c >> nut;

	for (ll i = 0; i < c; i++) positions[0][i][0] = i;
	for (ll i = 0; i < c; i++) positions[0][i][1] = c - (i + 1);
	
	for (ll i = 1; i < c; i++) {

		for (ll j = 0; j < c; j++) {

			positions[i][j][0] = (positions[i - 1][j][0] + 1) % c;
			positions[i][j][1] = (positions[i - 1][j][1] + 1) % c;

		}

	}

	//Positions[i][j] -> i son las rotaciones, j es la posicion original, y almacena el indice en el que estaria tras todo

	for (ll i = 0; i < r; i++) {

		cin >> row;

		for (ll j = 0; j < c; j++) {

			bool can = true;

			for (ll indice = 0; indice < c; indice++) {
				
				if (nut[positions[j][indice][0]] == '1' && row[indice] == '1') {
					
					can = false;

				}

			}

			posible[i + 1][j][0] = can;

			can = true;

			for (ll indice = 0; indice < c; indice++) {
				
				if (nut[positions[j][indice][1]] == '1' && row[indice] == '1') {
					
					can = false;

				}

			}

			posible[i + 1][j][1] = can;

		}

	}

	for (ll i = 0; i < c; i++) {
		
		posible[0][i][0] = true;
		posible[0][i][1] = true;
	
	}

	memset(seen, false, sizeof(seen));
	flfl(0, 0);
	flfl2(0, 0);

	if (ans) cout << "Y\n";
	else cout << "N\n";

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false); 

    solve();
}