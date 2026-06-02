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
using hashmap = unordered_map<int,int>;
//lo submitee tambien con map y daba accepted
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int s; cin >> s;
    // x las dudas si hay repetidos
    set<int> el; 
    forn(i,s){
        int x; cin >> x;
        el.insert(x);
    }
    vector<int> e;
    for(int x: el){e.pb(x);}
    // saque los repetidos arriba

    s = sz(e);
    // yo se que (a * b) + c = (f + e) * e
    // pruebo todas las combinaciones de ambos lados en o(10 a la 6)
    // y voy fijandome si hay matching, voy a usar unordered map
    int t = (s * s * s);
    hashmap p1(t);
    hashmap p2(t);
    for(int a : e){
        for(int b : e){
            for(int c: e){
                int f = a * b + c;
                int s = (a + b) * c;
                p1[f]++;
                if(c != 0){ // porque si c es igual a cero lo que esta a la izquierda no se puede dividir
                    p2[s]++;
                }
            }
        }
    }
    ll ans = 0;
    for(par p : p1){
        int num = p.first;
        ll pos = p.second;
        ll pos2 = p2[num];
        ans += pos * pos2;
    }
    cout << ans << endl;
}
