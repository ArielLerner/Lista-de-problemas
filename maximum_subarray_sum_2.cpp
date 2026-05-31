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
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n; cin >> n;
    int a; cin >> a;
    int b; cin >> b;
    vector<ll> acum(n+1);
    map<ll,int> is;
    acum[0] = 0;
    cin >> acum[1];
    ll rta = 1e9 ;
    rta = rta * rta * (-1);
    forr(i,2,n+1){
        ll x; cin >> x;
        acum[i] = acum[i-1] + x;
    }
    forn(i,n+1){
        int toAdd = i - a;
        int toErase = i - (b+1);
        if(toAdd >= 0){
            is[acum[toAdd]]++;
        }
        if(toErase >=0){
            is[acum[toErase]]--;
        }
        while(is.begin()->second == 0){
            is.erase(is.begin());
        }
        if(!is.empty()){
            rta = max(rta,acum[i] - is.begin()->first);
        }
    }
    cout << rta << endl;
}
