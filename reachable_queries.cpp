// Pensaba que aun usando bitsets no entraba
// Me tuve que spoilear de la solucion, para enterarme de que si
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
using par = pair<int,int>;
vector<vector<int>> ady;
vector<int> ans;
vector<bool> done;
void dfs(int i, vector<bitset<50002>> &c ){
    done[i] = true;
    c[i].set(i);
    for(int hijo : ady[i]){
        if(!done[hijo]){
            dfs(hijo,c);
        }
        c[i] = c[i] | c[hijo];
    }
    ans[i] = c[i].count();
}
int main(){
    //freopen("stdin.txt","r",stdin);
    int n, m; cin >> n >> m;
    vector<bitset<50002>> c(n);
    ady.resize(n);
    forn(i,m){
        int a,b; cin >> a >> b;
        ady[a-1].pb(b-1);
    }
    done.resize(n);
    ans.resize(n,0);
    forn(i,n){
        if(!done[i]){
            dfs(i,c);
        }
        cout << ans[i] << endl;
    }
}
