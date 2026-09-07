#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii; 
typedef vector<vii> wgraf;
typedef pair<int,ii> edge;
 
#define UNVISITED 0
#define VISITED 1
#define pb push_back
#define F first
#define S second
string anos[12]={"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map <string, int> nacimiento;

string animal (int ano){
  int a=0, y=2021;
  while (y<ano) {
    y++;
    a++;
    if (a==12) a=0;
  }

  while (y>ano) {
    y--;
    a--;
    if (a==-1) a=11;
  }

  return anos[a];
}
 
void SOLVE(){
  string vaca1, born, in, relacion, ano, year, from, vaca2;
  int n, diferencia;

  nacimiento["Bessie"]=2021;

  cin >> n;

  for (int i=0; i<n; i++){
    cin >> vaca1 >> born >> in >> relacion >> ano >> year >> from >> vaca2;

    nacimiento[vaca1]=nacimiento[vaca2];
    do {
      if (relacion=="previous") nacimiento[vaca1]--;
      else nacimiento[vaca1]++;
    } while (animal(nacimiento[vaca1])!=ano);
  }

  diferencia=abs(nacimiento["Bessie"]-nacimiento["Elsie"]);
  cout << diferencia;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  //cin >> t;
  while(t--){
    SOLVE();
  }
}