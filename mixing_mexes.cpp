#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i < (b); i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (b) -1 ; i >= (a); i--)
#define dforn(i,n) dforr(i,0,n)
#define pb push_back
#define sz(i) i.size()
#define dbg(x) cerr << #x << ":  " << x << endl
#define all(x) x.begin(),x.end()
using ll = long long int;
using namespace std;
int tMax = 1e6+10;
ll get_mex(vector<ll> &h, int st){
    forr(i,st,sz(h)){
        if(h[i] == 0 ){return i;}
    }
    return -1;
}
void solve(){
    ll n; cin >> n;
    vector<vector<ll>> hp(n);
    ll tot = 0;
    vector<vector<ll>> m(n);
    forn(i,n){
        ll s; cin >> s;
        tot +=s;
        hp[i].resize(s+10,0);
        m[i].resize(s);
        forn(pos,s){
            ll x; cin >> x;
            m[i][pos] = x;
            if(x < sz(hp[i])){
                hp[i][x]++;
            }
        }
    }
    vector<ll> h(tot+2,0);
    forn(x,sz(m)){
        forn(y,sz(m[x])){
            if(m[x][y] < sz(h)){
                h[m[x][y]]++;
            }
        }
    }
    ll ans = 0;
    // ahora calculo por cada uno las posibilidades
    ll op_tot = tot * (n-1);
    forn(i,n){
        // posibilidades de sacar
        ll mex  = get_mex(hp[i],0);
        ll pSacar = sz(m[i]) * (n-1);
        forn(pos,sz(m[i])){
            // sumo los mex de sacar la posicion
            ll v = m[i][pos];
            if(v < mex && hp[i][v] == 1){ // si baja el mex a v
                ans += (n-1) * v;
            }
            else{
                ans += mex * (n-1);
            }
        }
        // ahora sumo los mex donde crece
        ll new_mex = get_mex(hp[i],mex+1);
        ll times = h[mex];
        ans += new_mex * times;
        // me fijo cuantas posibilidades quedan y todas esas me aseguran de tener el mex
        ll p_rest = op_tot - pSacar - times;
        ans += p_rest * mex;
    }
    cout << ans << endl;
}
int main(){
    //freopen("stdin.txt","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
