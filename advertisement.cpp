#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll = long long int;
using par = pair<ll,ll>;
using matriz = vector<vector<int>>;
using hashmap = unordered_map<int,int>;
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    ll n; cin >> n;
    vector<ll> h(n);
    forn(i,n){cin >> h[i];}
    ll ans = 0;
    stack<par> op;
    forn(i,n-1){
        // primero agrego al stack la opcion de hacerlo de altura h[i]
        op.push(par(i,h[i]));
        // ahora me fijo si debo evaluar las opciones que en i + 1 no voy a poder seguir
        ll sigH = h[i+1];
        while(!op.empty() &&  sigH < op.top().second){
            ll ind = op.top().first;
            ll v = op.top().second;
            op.pop();
            ans = max(ans, (i - ind + 1) * v);
            if(op.empty() || sigH >= op.top().second){ // si es la ultima
                op.push(par( ind,sigH ) );
            }
        }
    }
    // ahora solo me queda evaluar las posibilidades que me quedaron al final
    int i = n-1;
    op.push(par(i,h[i]));
    while(!op.empty()){
        ll ind = op.top().first;
        ll v = op.top().second;
        op.pop();
        ans = max(ans, (i - ind + 1) * v);
    }
    cout << ans << endl;
}
