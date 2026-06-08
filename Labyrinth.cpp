#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i < (b); i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (b-1); i >= (a); i--)
#define dforn(i,n) dforr(i,0,n)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(i) i.size()
using namespace std;
using par = pair<int,int>;
using ll = long long int;
vector<par> posFree{
    par(1,0),
    par(-1,0),
};
vector<vector<bool>> done;
vector<string> lab;\
int n,m;
bool sePuede(int x,int y){
    if(x >= 0 && x < n && y >= 0 && y < m){
        if(!done[x][y] && lab[x][y] == '.'){
            return true;
        }
    }
    return false;
}
int main(){
   // freopen("input.txt","r",stdin);
    cin >> n >> m;
    int xs,ys; cin >> xs >> ys;
    xs--;ys--;
    int maxL,maxR; cin >> maxL >> maxR;
    done = vector<vector<bool>>(n,vector<bool>(m));
    lab.resize(n);
    forn(i,n){
        cin >> lab[i];
    }
    // condiciones a chequear al pasar a otra celda
    // 1. que exista // siempre // 1.a en bounds // 2. que no sea una pared
    // 2. que me queden movimientos
    vector<par> act = {par(xs,ys)}; 
    vector<par> sig;
    int d = 0;
    while(!act.empty()){
        forn(i,sz(act)){
            par p = act[i];
            if(done[p.first][p.second]){continue;}
            done[p.first][p.second] = true; 
            // ahora actualizo las otras posiciones
            int dy = p.second - ys;
            int R  = (dy + d) / 2;
            int L = (d - R);
            int x =p.first; int y = p.second;
            if(sePuede(x+1,y)){
                act.pb(par(x+1,y));
            }
            if(sePuede(x-1,y)){
                act.pb(par(x-1,y));
            }
            // y ahora debo chequear los costados
            if(sePuede(x,y+1) && R < maxR){
                sig.pb(par(x,y+1));
            }
            if(sePuede(x,y-1) && L < maxL){
                sig.pb(par(x,y-1));
            }
        }
        // ahora cambio todo
        act.clear();
        swap(act,sig);
        d++;
    }
    int ans = 0;
    forn(x,n){
        forn(y,m){
            if(done[x][y]){ans++;}
        }
    }
    cout << ans << endl;
}
