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
void solve(){
    int n; cin >> n;
    vector<ll> a,b;
    a = b = vector<ll>(n);
    forn(i,n){
        cin >> a[i];
        cin >> b[i];
    }
    ll ideal = 0;
    ll less = 1e18;
    forn(i,n){
        int sig = (i + 1) % n;
        ll x = max(0ll,a[sig] - b[i]);
        ideal += x;
        less = min(less,min(a[sig],b[i]));
    }
    cout << ideal + less << endl;
}
int main(){
    //freopen("C:/Users/Gamer/OneDrive/Escritorio/OIA/codeforces/input.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
