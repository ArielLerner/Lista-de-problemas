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
void solve(ll k){
    k--;
    ll p = 10;
    ll d = 1;
    while(k >= ((p - (p/10)) * d)){
        k-=(p - (p/10)) * d;
        d++;
        p *= 10;
    }
    // ahora se que el numero tiene
    // d digitos
    // y el siguiente numero es el p/10
    ll n = k / d + (p/10);
    d = k % d;
    string num = to_string(n);
    cout << num[d] << endl;
}
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int q; cin >> q;
    forn(i,q){
        ll k; cin >> k;
        solve(k);
    }
}
