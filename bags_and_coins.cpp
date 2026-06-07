// Lo programe de vuelta, porque el primer codigo accepted tenia muchos bugs y se podia hacer de mejor manera
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
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n, s; cin >> n >> s;
    vector<par> a(n);
    vector<int> h,c;
    h = c = vector<int>(n,-1);
    forn(i,n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    par may = a[sz(a)-1];
    a.pop_back();
    c[may.second] = may.first;
    s-= may.first;
    if(s < 0){ // si no alcanza
        cout << -1 << endl;
        return 0;
    }
    bitset<70002> act;
    bitset<70002> old;
    bitset<70002> changes;
    vector<int> f(70002,-1);
    old[0] = 1; 
    forn(i,sz(a)){
        int v = a[i].first;
        act = old | (old << v);
        changes = act ^ old; // me da los nuevos bits en 1
        int p = changes._Find_first();
        while(p < sz(changes)){
            f[p] = i;
            p = changes._Find_next(p);
        }
        swap(act,old); 
    }
    // reconstruyo ahora el subset sum
    if(s != 0 && f[s] == -1){
        cout << -1 << endl;
        return 0;
    }
    while(s){
        int i = f[s];
        c[a[i].second] = a[i].first;
        s-= a[i].first;
    }
    dforn(x,sz(a)){
        int i = a[x].second;
        int v =  a[x].first;
        if(c[i] != -1){continue;}
        c[may.second] = c[may.second] - v;
        h[may.second] = i;
        c[i] = v;
        may = a[x];
    }
    forn(i,n){
        cout << c[i] << " ";
        if(h[i] == -1){
            cout << 0 << endl;
        }
        else{
            cout << "1 " << h[i] + 1 << endl;
        }
    }
}
