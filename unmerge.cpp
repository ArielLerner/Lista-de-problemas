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
    n*= 2;
    vector<int> e(n);
    forn(i,n){
        cin >> e[i];
    }
    int nada = 1e9;
    vector<vector<int>> dp(n,vector<int>(n+1,nada)); // dp[elemento a procesar][tamano del conjunto] =~ minimo numero necesitado para poner en cuualquiera de los dos conjuntos
    dp[0][1] = e[0];  
    forn(i,sz(e)-1){
        int v = e[i+1];
        forn(tam,n){
            if(dp[i][tam] == nada){continue;}
            int newR = max(dp[i][tam],v);
            dp[i+1][tam+1] = min(dp[i+1][tam+1],newR);
            int tOp = (i + 2 -  tam);
            if(v > dp[i][tam]){
                dp[i+1][tOp] = min(dp[i+1][tOp],v);
            }
        }
    }
    if(dp[sz(e)-1][n/2] != nada){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
   int t; cin >> t;
   while(t--){
    solve();
   }
}
