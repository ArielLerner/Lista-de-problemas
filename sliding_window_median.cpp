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
    int n,k;
    cin >> n >> k;
    multiset<int> v;
    int a; cin >>a;
    int L = 0;
    int R = 0;
    v.insert(a);
    auto itMed = v.begin();
    vector<int> valores(n);
    valores[0] = a;
    if(k == 1){
        cout << a << " ";
    }
    //calculo los sliding windows
    forr(i,1,n){
        int x; cin >> x;
        valores[i] = x;
        v.insert(x);
        int med = *itMed;
        if(x >= med){R++;}
        else{L++;}
        if(sz(v) > k){ // si debo borrar un elemento
            int to_erase = valores[i-k];
            auto itE = v.find(to_erase);
            if(to_erase < med){
                L--;
                v.erase(itE);
            }
            if(to_erase > med){
                R--;
                v.erase(itE);
            }
            if(to_erase == med){
                // en este caso borro med directamente y paso al anterior
                if(L == 0){ // si; no hay elementos a la izq guardo el de la derecha
                    v.erase(itMed);
                    itMed = v.begin();
                    R--;
                }
                else{
                    L--;
                    itMed--;
                    v.erase(next(itMed));
                }
            }
        }
        // ahora debo acomodar la mediana
        // R - L = 0 or 1 siempre para que valga
        while(L > R){
            L--; R++;
            itMed--;
        }
        while(R - L > 1){
            R--; L++;
            itMed++;
        }
        if(sz(v) == k){
            cout << *itMed << " ";
        }
    }
    cout << endl;
}
