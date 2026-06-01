#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using par = pair<int,int>;
using ll = long long int;
using matriz = vector<vector<int>>;
int n,x,y;
bool isY(int b){
    if(b == 0 || b == x ){return false;}
    return true;
}
vector<int> juntar(matriz &c , int L , int R){
  vector<int> e;
  forr(i,L,R+1){
    forn(i2,sz(c[i])){
      e.pb(c[i][i2]);
    }
  }
  return e;
}
int q = 0;
bool query(vector<int> &e){
  q++;
  sort(all(e)); // x las dudas
  if(e.empty()){return false;}
  cout << "? " << sz(e) << " ";
  for(int x : e){cout << x+1 << " ";}
  cout << endl;
  cout.flush();
  int ans; cin >> ans;
  return isY(ans);
}
int bs(matriz &c){
  int L = 0;
  int R = sz(c)-1;
  while(L != R){
    int m =  (L+R) / 2;
    vector<int> e = juntar(c,L,m);
    bool ans = query(e);
    if(ans){R = m;}
    else{L = m+1;}
  }
  return L;
}
int bs(vector<int> &c){
  int L = 0;
  int R = sz(c)-1;
  while(L != R){
    int m =  (L+R) / 2;
    vector<int> e;
    forr(i,L,m+1){
      e.pb(c[i]);
    }
    bool ans = query(e);
    if(ans){R = m;}
    else{L = m+1;}
  }
  return L;
}

int main(){
  //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
  cin >> n >> x >> y;
  // la solucion tiene 3 pasos 
  // 1 voy dividiendo en conjuntos y voy comparando todos al mismo tiempo
  vector<int> ca; 
  vector<int> cb;
  bool foundY = false;
  matriz c(1);
  forn(i,n){c[0].pb(i);}
  while(!foundY){
  matriz c1(sz(c));
  matriz c2(sz(c));
    forn(con, sz(c)){
      int t = sz(c[con]);
      forn(i,sz(c[con])){
          int elemento = c[con][i];
        if(i < t/2){
          c1[con].pb(elemento);
        }
        else{
          c2[con].pb(elemento);
        }
      }
    }
    // aca ya cree los conjuntos
    vector<int> e = juntar(c1,0,sz(c1)-1);
    bool ans = query(e);
    if(ans){
      // si encuentro que hay un solo y en un conjunto
      // busco en que conjunto esta con binary search
      int index = bs(c1);
      ca = c1[index];
      cb = c2[index];
      //
      break;
    }
    // sino armo el nuevo c
    c = c1;
    forn(i,sz(c2)){
      c.pb(c2[i]);
    }
  }
  // aca ya tengo ca y cb
  // hago binary search y busco cada uno
  int i1 = bs(ca);
  int i2 = bs(cb);
  int a = ca[i1] + 1; int b = cb[i2] + 1;
  if(a > b){swap(a,b);}
  cout << "! " << a << " " << b << endl;
 // cout << q << endl;
}
