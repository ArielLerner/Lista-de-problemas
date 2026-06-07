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
    vector<int> has(10);
    int n; cin >> n;
    vector<int> v(n);
    forn(i,n){cin >> v[i];}
    bool ans = false;
    int mayor = -1;
    dforn(i,sz(v)){
        mayor = max(v[i],mayor);
        has[v[i]]++;
        if(v[i] >= mayor){
            //seteo al menor posible
            continue;
        }
        forn(d,10){
            if(has[d] && d > v[i]){
                has[d]--;
                v[i] = d;
                break;
            }
        }
        ans = true;
        int vd = 0;
        forr(p,i+1,sz(v)){
            while(!has[vd]){
                vd++;
            }
            has[vd]--;
            v[p] = vd;
        }
        break;
    }
    if(!ans){
        cout << -1 << endl;
        return;
    }
    forn(i,sz(v)){cout << v[i];}
    cout << endl;
}
int main(){
    //freopen("C:/Users/Gamer/OneDrive/Escritorio/OIA/codeforces/input.txt","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
