#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i < (b); i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (b-1); i >= (a); i--)
#define dforn(i,n) dforr(i,0,n)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(i) i.size()
using namespace std;
using ll = long long int;
using par = pair<ll,ll>;
vector<vector<par>> ady;
vector<ll> val;
ll nada = 1e16;
void dfs(ll n, ll v){
    val[n] = v;
    for(auto [to,sum]: ady[n]){
        if(val[to] == nada){
            dfs(to,v+sum);
        }
    }
}
int main(){
    //freopen("C:/Users/Gamer/OneDrive/Escritorio/OIA/codeforces/stdin.txt","r",stdin);
    // creo el grafo
    int n,m; cin >> n >> m;
    ady.resize(n+1);
    forn(i,m){
        int l,r,v;
        cin >> l >> r >> v;
        ady[l-1].pb(par(r,v));
        ady[r].pb(par(l-1,-v));
    }
    val.resize(n+1,nada);
    forn(i,n+1){
        if(val[i] == nada){
            dfs(i,0);
        }
    }
    // ahora voy a chequear que exista solucion fijandome en cada m
    forn(from,n){
        for(auto [to,v] : ady[from]){
            if(val[from] != val[to] - v){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    forn(i,n){
        cout << val[i+1] - val[i] << " ";
    }
    cout << endl;
}
