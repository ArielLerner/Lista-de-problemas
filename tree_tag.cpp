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
using matriz = vector<vector<int>>;
int dfsD(int x, int padre, int dest, int dAcum, matriz &ady){
    if(x == dest){return dAcum;}
    for(int c : ady[x]){
        if(c == padre){continue;}
        int r = dfsD(c,x,dest,dAcum+1,ady);
        if(r != -1){return r;}
    }
    return -1; 
}
int distancia(int a, int b, matriz &ady){
    return dfsD(a,-1,b,0,ady);
}
int camMax(int x, int p, matriz &ady, int &ans){
    vector<int> d;
    for(int c: ady[x]){
        if(c == p){continue;}
        d.pb(camMax(c,x,ady,ans)); // agrego las maximas distancias a los hijos
    }
    sort(d.begin(),d.end(),greater<int>());
    if(sz(d) == 1){
        ans = max(ans,d[0]);
        return d[0] + 1;
    }
    if(sz(d) > 1){
        ans = max(ans,d[0] + d[1]);
        return d[0] + 1;
    }
    return 1;
}
bool solve(){ // false es alice, true es bob
    int n,a,b,da,db;
    cin >> n >> a >> b >> da >> db;
    a--; b--;
    matriz ady(n);
    forn(i,n-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        ady[u].pb(v);
        ady[v].pb(u);
    }
    if(db <= 2 * da){
        return false;
    }
    int dist = distancia(a,b,ady);
    if(dist <= da){
        return false;
    }
    // ultimo caso, debe haber un camino mayor o igual a 2 * da + 1
    // debo hacer dp para buscar el camino mas largo 
    int cMax = 0;
    camMax(0,-1,ady,cMax);
    if(cMax < 2 * da + 1){
        return false;
    }
    return true;
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int t; cin >> t;
    while(t--){
        bool ans = solve();
        if(ans){
            cout << "Bob" << endl;
        }
        else{
            cout << "Alice" << endl;
        }
    }
}
