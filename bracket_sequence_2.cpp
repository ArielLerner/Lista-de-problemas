// del verano de 2025
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >= a; i--)
#define dforn(i,n) dforr(i,0,n)
#define all(x) x.begin(),x.end()
using namespace std;
using par = pair<int,int>;
using ll = long long int;
using hashmap = unordered_map<int,int>;
using matriz = vector<vector<int>>;
#define sz(x) x.size()
ll mod = 1e9  + 7;
int exp(ll b, ll pot){
    if(pot == 0){return 1;}
    if(pot % 2 == 1){
        return (exp(b,pot-1) * b) % mod;
    }
    ll r = exp(b,pot/2);
    return (r * r) % mod;
}
vector<ll> fact;
void calcularF(){
    fact.resize(1e6 + 10);
    fact[0] = 1;
    forr(i,1,sz(fact)){
        fact[i] = (fact[i-1] * i) % mod;
    }
}
ll invFact(int i){
    ll f = fact[i];
    return exp(f,mod-2);
}
ll comb(ll e, ll sel){
    ll r = (fact[e] * invFact(sel)) % mod;
    return (r * invFact(e-sel)) % mod;
}
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n; cin >> n;
    calcularF();
    string s; cin >> s;
    int cerrados = 0;
    int abiertos = 0;
    bool cond_prefix = true;
    forn(i,sz(s)){
        if(s[i] == '('){
            abiertos++;
        }
        else{
            cerrados++;
        }
        // chequeo si prefix esta bien
        if(cerrados > abiertos){
            cond_prefix = false;
        }
    }
    if(n % 2 == 1  || !cond_prefix || abiertos > n/2){
        cout << 0 << endl;
        return 0;
    }
    if(abiertos == n/2){
        cout << 1 << endl;
        return 0;
    }
    int x = n/2 - cerrados;
    int y = n/2 - abiertos;
    // se puede si pasa por aca
    ll r1 = comb(x+y,x);
    ll r2 = comb(x+y,x+1);
    ll rta = r1 - r2;
    if(rta < 0){rta+= mod;}
    cout << rta << endl;
}
