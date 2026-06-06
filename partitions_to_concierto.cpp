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
char redonda = 'r';
char blanca = 'b';
string toConciertos(vector<int> &e){
    string ans = "";
    for(int x : e){
        ans += blanca; // para que todas las redondas deban ir al mismo lado
        forn(i,x+1){ // agrego 1 de mas para compensar el compas que despues agrego del otro lado
            ans += redonda;
        }
        ans += blanca; // dejo los dos compases finalizados
    }
    return ans;
}
int main(){
    int n; cin >> n; // cantidad de numeros
    vector<int> e(n);
    forn(i,n){cin >> e[i];}
    cout << toConciertos(e);
}
