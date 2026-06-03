// La idea principal es hacer un knapsack
// Aunque tiene un par de modificaciones
// Sabiendo qeu hay 2 * sqrt(n) posibles numeros
// 1. se hace un knapsack normal la primera pasada
// 2. y despues se hace knapsack solo sobre los valores actualizados
// y se repite esto por cada aparicion de un numero
// Como la complejidad de el knapsack para las repeticiones es sz(updated) * apariciones 
// Para hacer que hayan menos apariciones uso rand() para cambiar el orden de procesamiento del
// knapsack, asi se encuentra el mejor caso un poco mas rapido
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
matriz ady;
vector<bool> done;
int buscarC(int x){
    done[x] = true;
    int ans = 1;
    for(int c : ady[x]){
        if(done[c]){continue;}
        ans += buscarC(c);
    }
    return ans;
}
bool isLucky(int x){
    if(x == 0){return false;}
    bool isLucky = true;
    while(x > 0){
        int digit = x % 10;
        x/= 10;
        if(digit == 4 || digit == 7){continue;}
        else{isLucky = false; break;}
    }
    return isLucky;
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);

    int n,m; cin >> n >> m;
    ady.resize(n);
    forn(i,m){
        int u,v;
        cin >> u >> v;
        u--;v--;
        ady[u].pb(v);
        ady[v].pb(u);
    }
    done.resize(n,false);
    vector<int> el(n+1,0);
    forn(i,n){
        if(!done[i]){
            el[buscarC(i)]++;
        }
    }
    vector<par> e;
    forn(i,n+ 1){
        if(el[i] > 0){
            e.pb(par(i,el[i]));
        }
    }
    // ahora voy a hacer swaps random para mejorar el worst case
    srand(time(0));
    forn(i,sz(e)){
        int r1 = rand() % (sz(e));
        int r2 = rand() % (sz(e));
        swap(e[r1],e[r2]);
    }
    // ahora ya tengo los numeros del knapsack em (numero , cantidad)
    // voy a hacer un knapsack pero a partir de la segunda vez que pase por un numero
    // solo actualizo las posiciones que se actualizaron anteriormente
    int nada = 1e7;
    vector<int> knap(n+1,nada);
    knap[0] = -1;
    for(par p : e){
        int num = p.first;
        int q = p.second;
        vector<int> updated;
        vector<int> upNext;
        forn(times,q){
            if(times == 0){
                // debo recorrer el knapsack completo
                dforn(i,sz(knap) - num){
                    int sig = num + i;
                    if(knap[i] + 1 < knap[sig]){
                        updated.push_back(sig);
                        knap[sig] = knap[i] + 1;
                    }
                }
            }
            else{
                // solo recorro updated
                for(int x : updated){
                    if(num + x >= sz(knap) ){continue;}
                    int sig = num + x;
                    if(knap[x] + 1 < knap[sig]){
                        upNext.push_back(sig);
                        knap[sig] = knap[x] + 1;
                    }
                }
                // swapeo updated
                updated.clear();
                swap(updated,upNext);
            }
        }
    }
    int ans = nada;
    forn(i,sz(knap)){
        if(!isLucky(i)){continue;}
        ans = min(ans,knap[i]);
    }
    if(ans == nada){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}
