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
int sigId = 1;
void dfs(int n, int cant,  vector<bool> &done ,
    vector<vector<par>> &ady){ 
    done[n] = true;
    for(par p : ady[n]){
        int h = p.first;
        if(!done[h] && p.second != cant){
            dfs(h,cant,done,ady);
        }
    }
}
bool conexo(vector<vector<int>> &aristas,int ar, int st, vector<vector<par>> &ady, int n){
    int a,b;
    a = b = -1;
    if(ar >= 0 ){
        a = aristas[ar][0];
        b = aristas[ar][1];
    }
    vector<bool> done(n);
    dfs(st,ar,done,ady);
    bool ans = true;
    forn(i,n){
        if(i == a || i == b){
            if(!done[i] && sz(ady[i]) - 1 > 0){
                ans = false; // si no es conexo
            }
            continue;
        }
        if(!done[i] && sz(ady[i]) > 0){
            ans = false; // si no es conexo
        }
    }
    return ans;
}
void invertir(vector<int> &x, set<int> &imp){
    for(int a : x){
        if(imp.count(a)){
            imp.erase(a);
        }
        else{
            imp.insert(a);
        }
    }
}
bool cond(set<int> &Imp, int ar, int to){
    if(sz(Imp) == 0){
        return true;
    }
    if(sz(Imp) == 2 && Imp.count(to)){
        return true;
    }
    return false;
}
void solve(int n, int m){
    sigId = 1;
    vector<vector<int>> aristas(m);
    vector<int> grado(n);
    vector<vector<par>> ady(n);
    set<int> Imp;
    aristas.assign(m,{});
    forn(i,n){
        int k; cin >> k;
        forn(i2,k){
            int link; cin >> link;
            aristas[link].pb(i);
        }
    }
    forn(i,sz(aristas)){
        int a = aristas[i][0];
        if(sz(aristas[i]) == 2){
            int b = aristas[i][1];
            grado[a]++; grado[b]++;
            ady[a].pb(par(b,i));
            ady[b].pb(par(a,i));
        }
        else{
            ady[a].pb(par(a,i));
        }
    }
    forn(i,sz(grado)){
        if((grado[i] % 2) == 1){
            Imp.insert(i);
        }
    }
    int r = -1;
    dforn(i,m){
        int a = aristas[i][0];
        if(sz(aristas[i]) == 1){
            if(cond(Imp,i,a) && conexo(aristas,-1,a,ady,n)){r = i;}
            continue;
        }
        int b = aristas[i][1];
        // saco la conexion a - b
        invertir(aristas[i],Imp);
        forn(i2,2){
            if(cond(Imp,i,a) && conexo(aristas,i,a,ady,n)){r = i;}
            swap(a,b);
        }
        // pongo la conexion a - b
        invertir(aristas[i],Imp);
    }
    cout << r << endl;
}
int main(){
    //freopen("stdin.txt","r",stdin);
    while(true){
        int n,m; cin >> m >> n;
        if(m == 0 && n == 0){break;}
        solve(n,m);
    }
}
