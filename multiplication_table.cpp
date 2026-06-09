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
ll n;
ll menores(ll x){
    ll ans = 0;
    dforr(fila,1,n+1){
        ans += min(n,x / fila);
    }
    return ans;
}
void solve(ll act){
    n = act;
    if(n == 1){cout << 1 << endl; return;}
    ll exp = n * n / 2;
    ll L = 1;
    ll R = n * n;
    while(R != L){
        ll mid = (L + R + 1) / 2;
        ll ans = menores(mid);
        if(ans > exp){
            R = mid-1; 
        }
        else{
            L = mid;
        }
    }
    cout << L + 1 << endl;
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    cin >> n;
    solve(n);
}
