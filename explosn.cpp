#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using par = pair<int,int>;
using ll = long long int;
using matriz = vector<vector<int>>;
int n;
vector<int> h;
matriz dp;
matriz bucles;
matriz padres;
void dfs(int i, vector<bool> &in_loop, vector<bool> &done){
    if(in_loop[n]){return;}
    done[i] = true;
    // ahora me fijo que este calculado para los padres
    // y voy calculando la dp
    int notP , perp = 0;
    for(int p : padres[i]){
        if(!done[p]){
            dfs(p,in_loop,done);
        }
        dp[1][i] += min(dp[0][p],dp[1][p]); // si es perpetrador, el que lo apunta puede ser cualquier cosa
        dp[0][i] += dp[1][p]; // si no es, el que lo apunta debe ser perpetrador
    }
    dp[1][i]++; // porque i es perpetrador
}
par dpTree(int i , int padre){ // dp sin contar loop
    int dp0,dp1; dp0 = dp1 = 0;
    for(int p : padres[i]){
        if(p == padre){continue;}
        dp1 += min(dp[0][p],dp[1][p]);
        dp0 += dp[1][p];
    }
    dp1++;
    return par(dp0,dp1);
}
void solve(){
    cin >> n;
    h.assign(n,0);
    forn(i,n){
        cin >> h[i]; h[i]--;
    }
    bucles = padres = matriz(n);
    // hago un dfs para encontrar ciclos
    vector<bool> done(n,false);
    vector<bool> in_loop(n,0);
    forn(i,n){
        if(!done[i]){
            // hago el dfs
            int act = i;
            int hijo = h[act];
            deque<int> num;
            int first_in_loop = -1;
            while(!done[act]){
                done[act] = true;
                num.pb(act);
                if(done[hijo]){
                    first_in_loop = hijo;
                }
                act = hijo;
                hijo = h[act];

            }
            // ahora me fijo el loop
            bool salioPri = false;
            forn(i2,sz(num)){
                if(num[i2] == first_in_loop){salioPri = true;}
                if(salioPri){
                    bucles[i].pb(num[i2]);
                }
            }
        }
    }
    // ahora ya separe los bucles // creo el grafico con los padres para poder hacer el arbol
    forn(i,n){
        int padre = i;
        int hijo = h[i];
        padres[hijo].pb(padre);
    }
    // ahora voy a actualizar la dp para los nodos que no estan in loop
    // dp representa la mejor posibilidad del subtree [1] si i es perpetrador || [0] si i no es perpetrador
    // hago un dfs para calcular los hijos y despues voy al padre
    dp.assign(2,vector<int>(n,0));
    //dp.assign(2,vector<int>(n,0));
    done.assign(n,false);
    forn(i,n){
        if(!in_loop[i] && !done[i]){dfs(i,in_loop,done);}
    }
    // ahora ya calcula la dp para los que no estan en bucle
    // para los que estan en bucle sirve mientras que no haya 2 no perp seguidos, hago la misma dp
    // aunque la divido en 2 porque no puede pasar que si empieza con no perp termine con no perp
    int ans = 0;
    for(vector<int> b : bucles){
        if(sz(b) == 0){continue;}
        // creo la dp
        int t = sz(b);
        matriz dp0(2,vector<int>(t,1e9));
        matriz dp1(2,vector<int>(t,1e9));
        par ans0 = dpTree(b[0],b[t-1]);
        dp0[0][0] = ans0.first;
        dp1[1][0] = ans0.second;
        // ya cree la dp, ahora voy a completarla buscando las mejores posibilidades
        forr(i,1,t){
            par ansI = dpTree(b[i],b[i-1]); // tengo que poner dp0 y dp1
            dp0[1][i] = ansI.second;
            dp0[0][i] = ansI.first;
            dp0[1][i] += min(dp0[0][i-1],dp0[1][i-1]);
            dp0[0][i] += dp0[1][i-1];
            // ahora lo mismo con dp1
            dp1[1][i] = ansI.second;
            dp1[0][i] = ansI.first;
            dp1[1][i] += min(dp1[0][i-1],dp1[1][i-1]);
            dp1[0][i] += dp1[1][i-1];
        }
        // ahora busco la mejor rta
        int best = 1e9;
        best = min(best,dp0[1][t-1]);
        best = min(best,dp1[1][t-1]);
        best = min(best,dp1[0][t-1]);
        ans+= best;
    }
    cout << ans << endl;
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
