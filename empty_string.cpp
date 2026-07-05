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
#define  par  pair<int,int>
using namespace std;
int mod = 1e9+7;
vector<vector<int>> ways;
string s;
int t = 600;
vector<ll> fact(t);
vector<ll> inv(t);
ll fastExp(ll b, ll pot){
    if(pot == 0){return 1;}
    if(pot % 2 == 1){
        return (fastExp(b,pot-1) * b) % mod;
    }
    else{
        ll r = fastExp(b,pot/2);
        return (r * r) % mod;
    }
    return -1;
}
void inicializar(){
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    forr(i,2,sz(fact)){
        fact[i] = (fact[i-1] * i) % mod;
        inv[i] = fastExp(fact[i],mod-2);
    }
}
ll sb(ll stars, ll bars){
    ll div = (inv[stars] * inv[bars]) % mod;
    return (fact[stars + bars] * div) % mod;
}
int main(){
    //freopen("stdin.txt","r",stdin);
    inicializar();
    cin >> s;
    ll n = sz(s);
    ways.resize(n,vector<int>(n,0));
    // lo trato de hacer iterativo
    forr(t,1,n+1){
        if((t % 2) == 1){continue;}
        forn(L,n-t+1){
            int R = L + t -1;
                if(L == R){
                    ways[L][R] = 0;
                    continue;
                }
                char ch = s[L];
                ll ans = 0;
                forr(i,L+1,R+1){
                    if(s[i] != ch){continue;}
                    // busco las formas donde junto en L con i despues de resolver (L; i)
                    // me quedan dos intervalos [L+1 , i] , [i+1, R]
                    ll w1,w2;
                    w1 = w2 = 1;
                    if(L+1 <= i-1){w1 = ways[L+1][i-1];}
                    if(i+1 <= R){w2 = ways[i+1][R];}
                    ll op1 = (i - L + 1) / 2;
                    ll op2 = (R - i + 1) / 2;
                    ll wt = (w1 * w2) % mod;
                    int orden_op = sb(op1,op2);
                    ans = (ans + wt * orden_op) % mod;
                }
                ways[L][R] = ans % mod;
        }
    }
    cout << ways[0][n-1] << endl;
}
