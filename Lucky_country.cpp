// knapsack
// optimizado dividiendo en modulos y usando deque para mantener los mejores indexes para actualizar
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
#define vTop front().second
#define iTop front().first
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
    int nada = 1e7;
    vector<int> knap(n+1,nada);
    knap[0] = -1;
    for(par p : e){
        int num = p.first;
        int q = p.second;
        // aca voy a hacer la knap
        // voy a dividir la knapsack en a % num
        forn(mod, num){
            deque<par> dq;
                // guardo los i,q / knap[i * num + mod] = i,q
                // los guardo ordenados de mas cercano a mas lejano y de peor a mejor
            int i = 0;
            while(num * i + mod < sz(knap)){
                int act = num * i + mod;
                int v = knap[act];
                while(!dq.empty() && (v - dq.vTop) <= (i - dq.iTop)){
                    dq.pop_front();
                }
                dq.push_front(par(i,v));
                // ahora voy a buscar la mejor posibilidad que esta en dq.back()
                while(!dq.empty() &&  (i - dq.back().first) > q){
                    dq.pop_back();
                }
                int iBack = dq.back().first;
                int vBack = dq.back().second;
                int rta = vBack +  (i - iBack);
                knap[act] = min(knap[act],rta);
                //
                i++;
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
