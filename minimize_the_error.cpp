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
int main(){
    ll n, k1, k2;
    cin >> n >>k1 >> k2;
    ll k =  k1 + k2;
    multiset<ll,std::greater<ll>> d;
    vector<ll> a,b;
    a = b = vector<ll>(n);
    forn(i,n){
        cin >> a[i];
    }
    forn(i,n){cin >> b[i];}
    forn(i,n){
        d.insert(abs(a[i] - b[i]));
    }
    while(k--){
        ll x = *d.begin();
        d.erase(d.begin());
        x = abs(x-1);
        d.insert(x);
    }
    ll ans = 0;
    for(ll x : d){
        ans = ans + (x * x);
    }
    cout << ans << endl;
}
