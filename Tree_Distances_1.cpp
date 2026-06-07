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
vector<vector<int>> ady;
vector<int> dist;
void searchD(int i, int p , int d){
    dist[i] = d;
    for(int c : ady[i]){
        if(c == p){continue;}
        searchD(c,i,d+1);
    }
}
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n; cin >> n;
    ady.resize(n);
    dist.resize(n);
    forn(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        ady[a].pb(b);
        ady[b].pb(a);
    }
    searchD(0,-1,0); 
    // busco la distancia del 0 con todos
    // porque el que mayor distancia tiene es parte de un diametro posible
    int a = 0;
    forn(i,sz(dist)){
        if(dist[i] > dist[a]){
            a = i;
        }
    }
    searchD(a,-1,0); // busco ahora su complemento del diametro que es el nodo con mayor distancia de a
    vector<int> distA = dist;
    int b = a;
    forn(i,sz(dist)){
        if(dist[i] > dist[b]){
            b = i;
        }
    }
    searchD(b,-1,0);
    vector<int> distB = dist;
    forn(i,n){
        int dMax = max(distA[i],distB[i]) ;
        cout << dMax << " ";
    }
    cout << endl;
}
