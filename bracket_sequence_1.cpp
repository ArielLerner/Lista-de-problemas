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
int main(){
    //freopen("C:\\Users\\Gamer\\OneDrive\\Escritorio\\OIA\\inOut\\stdin.txt","r",stdin);
    int n; cin >> n;
    calcularF();
    if(n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    ll comb = (fact[n] * invFact(n/2)) % mod;
    comb =  (comb * invFact(n/2)) % mod;
    comb = comb * exp((n/2)+1,mod-2);
    cout << comb % mod << endl;
}
