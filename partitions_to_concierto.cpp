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
string blancaP = "b*";
string negra = "n";
string toConciertos(vector<int> &e){
    string ans = "";
    forn(i,sz(e)){
        int x = e[i];
        if(i % 2 == 0){// para que todas las redondas deban ir al mismo lado
            ans += blanca; 
        }
        else{
            ans+= blancaP;
        }
        forn(i,x+1){ // agrego 1 de mas para compensar el compas que despues agrego del otro lado
            ans += redonda;
        }
        //  dejo los dos compases finalizados
        // si trato de dejar los dos en el medio, despues no puedo continuar
        if(i % 2 == 0){
            ans += blanca;
        }
        else{
            ans+= negra;
        }
    }
    return ans;
}
int main(){
    int n; cin >> n; // cantidad de numeros
    vector<int> e(n);
    forn(i,n){cin >> e[i];}
    cout << toConciertos(e);
}
