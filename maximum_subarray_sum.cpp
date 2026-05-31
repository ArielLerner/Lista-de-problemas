// resuelto en el verano de 2025
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >= a; i--)
#define dforn(i,n) dforr(i,0,n)
using namespace std;
using par = pair<int,int>;
using ll = long long int;
int main(){
    //freopen("C:/Users/Gamer/OneDrive/Escritorio/OIA/codeforces/stdin.txt","r",stdin);
    int n; cin >> n;
    vector<ll> f(n);
    cin >> f[0];
    ll rta = f[0];
    forr(i,1,n){
        ll nro; cin >> nro;
        f[i] = max(nro,f[i-1]+nro);
        rta = max(rta,f[i]);
    }
    cout << rta << endl;
}
