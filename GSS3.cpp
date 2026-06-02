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
int nada = -1e9;
struct sub{
    int sum, best, left, right;
    sub(){
        sum = best = left = right = nada;
    }
    sub(int s, int b, int l, int r){
        sum = s; best = b; left = l; right = r;
    }
    bool vacio(){
        if(sum == nada){return true;}
        return false;
    }
};
sub vacio = sub();
sub unir(sub &a , sub&b){
    if(a.vacio()){return b;}
    if(b.vacio()){return a;}
    int best = max(a.best,b.best);
    best = max(best,a.right + b.left);
    int sum = a.sum + b.sum;
    int left = max(a.left, a.sum + b.left);
    int right = max(b.right,b.sum + a.right);
    return sub(sum,best,left,right);
}
vector<sub> tree;
vector<int> izq;
vector<int> der; // son los vectores de los indices de cada posicion
int priN;
void actualizar(int p){
    tree[p] = unir(tree[2 * p],tree[2 * p + 1]);
}
void change(int p , int v){ // contando a p desde 0 a n-1
    p+=priN;
    tree[p] = sub(v,v,v,v);
    p /= 2;
    while(p != 0){
        actualizar(p);
        p/=2;
    }
}
sub query(int L, int R, int p){
    // definir tl y tr
    int tl = izq[p];
    int tr = der[p];
    if(tr < L || tl > R){return vacio;}
    if(L <= tl && tr <= R){return tree[p];}
    sub pri = query(L,R,2 * p);
    sub sec = query(L,R,2 * p + 1);
    return unir(pri,sec);
}
void iniciar(int n, vector<int> &e){
    int elem = 2 * n;
    int l2 = ceil(log2(elem));
    int tam = (1 << l2);
    tree.resize(tam,vacio);
    izq = der = vector<int>(tam);
    priN = tam / 2;
    forn(i,priN){
        if(i < sz(e)){
            int v  = e[i];
            tree[priN + i] = sub(v,v,v,v);           
        }
        izq[i + priN] = der[i + priN] = i;
    }
    dforr(i,1,priN){
       actualizar(i);
       izq[i] = izq[2 * i];
       der[i] = der[2 * i + 1];
    }
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n; cin >> n;
    vector<int> e(n);
    forn(i,n){
        cin >> e[i];
    }
    iniciar(n,e);
    int m; cin >> m;
    forn(i,m){
        int type, a ,b;
        cin >> type >> a >> b;
        if(type == 0){
            change(a-1,b);
        }
        else{
                sub ans = query(a-1,b-1,1);
            cout << ans.best << endl;
        }
    }
}
