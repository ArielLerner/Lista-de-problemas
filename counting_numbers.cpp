// codigo del verano de 2025
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
using namespace std;
using ll = long long int;
using par = pair<int,int>;
using matriz = vector<vector<int>>;
vector<int> simulacion;
void cuantosRepHay(int max){
    simulacion.resize(max,0);
    forr(i,1,max){
        simulacion[i] = simulacion[i-1]; 
        if( i == 997){
            int test = 1;
        }
        int n = i;
        int prev = n % 10;
        n = n / 10;
        bool updated = false;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            if(digit == prev){
                updated = true;
            }
            prev = digit;
        }
        if(updated){
            simulacion[i]++;
        }
    }
}
int noSePuedeApartir(ll x){
    int prev = x % 10;
    int d = 1;
    int rta = -1;
    while(x != 0){
        x = x / 10;
        int sig = x % 10;
        if(prev == sig){rta = max(rta,d);}
        d++;
        prev = sig;
    }
    return rta-1;
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    ll a,b;
    cin >> a; a--;
    int initialA = a + 1;
    cin >> b; b++;
    int noA = noSePuedeApartir(a);
    int noB = noSePuedeApartir(b);
    ll pe = 0;
    vector<ll> f(10,1);
    vector<ll> fSig(10,0);
    int digito = 0;
    while(a != 0 || b != 0){
        int da = a % 10;
        int db = b % 10;
        a = a / 10;
        b = b / 10;
        forn(prox,f.size()){
            forn(prev,f.size()){
                if(prox == prev){continue;}
                fSig[prox] += f[prev];
            }
        }
        // tengo que calcular las posibilidades especiales
        // si llego con todos los bits iguales hasta aca debo 
        // sumar solo los bits mayores a min o menores a max
        // si son iguales ya los calcule
        if(a != b){
            if(digito >= noA){
            forr(i,da + 1, f.size()){
                if(a % 10 != i){
                    pe += f[i];
                }
            }
            }
            if(digito >= noB){
            forr(i,0,db){
                if(b % 10 != i){
                    pe += f[i];
                }
 
            }
            }
        }
        else{
            if(digito >= noA){
            forr(i,da + 1, db){
                if(a % 10 != i){
                    pe += f[i];
                }
 
            }
            }
        }
        swap(f,fSig);
        fSig.assign(10,0);
        digito++;
    }
    if(initialA == 0){pe++;}
    cout << pe << endl;
}
