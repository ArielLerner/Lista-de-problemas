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
using par = pair<int,int>;
using matriz = vector<vector<int>>;
using hashmap = unordered_map<int,int>;
char tree = '*';
matriz h;
vector<string> f;
void calcularAltura(int x, int y){
    if(f[x][y] == tree){h[x][y] = 0; return;}
    if(x == 0){h[x][y] = 1; return;}
    h[x][y] = h[x-1][y]+1;
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n,m; cin >> n >> m;
    f = vector<string>(n);
    forn(i,n){
        cin >> f[i];
    }
    // voy a transformar el problema en un monton de advertisments (cses)
    // suponiendo que hay una fence desde x = [0;i] y busco la mejor posibilidad
    // busco el mejor rectangulo que va de[x ; x - algo] [y ; y - algo]
    int ans = 0;
    h = matriz(n,vector<int>(m));
    forn(x,n){
        stack<par> op; // <first index, altura> 
        forn(i,m){calcularAltura(x,i);}
        forn(i,m){
            int alt = h[x][i];
            op.push(par(i,h[x][i]));
            int altSig = -1;
            if(i + 1 < m){ // si hay siguiente
                altSig = h[x][i+1];
            }
            while(!op.empty() && altSig < op.top().second){
                int iPri = op.top().first;
                int a = op.top().second;
                op.pop();
                ans = max(ans, (i - iPri + 1) * a);
                if(op.empty() ||  altSig >= op.top().second){
                    // si el loop termina aca, entonces pruebo bajar la altura del ultima a aSig
                    op.push(par(iPri,altSig));
                }
            }
        }
    }
    cout << ans << endl;
}
