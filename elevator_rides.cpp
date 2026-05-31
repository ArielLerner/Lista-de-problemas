// resuelto en el verano de 2025
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
using namespace std;
int bits;
int maxW;
vector<int> w;
vector<int> f;
vector<int> ult;
int main(){
   // freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
 
    cin >> bits;
    cin >> maxW;
    w.resize(bits);
    forn(i,bits){
        cin >> w[i];
    }
    f.resize( ( 1 << bits) , 1e9 + 1);
    ult.resize( ( 1 << bits) , 1e9 + 1);
    f[0] = 1;
    ult[0] = 0;
    forr(i,1,f.size()){
        forn(b,bits){
            if(i & (1 << b)){ // si tiene el bit b
            int prev = i - (1 << b);
            bool entra = (ult[prev] + w[b]) <= maxW;
            if(f[prev] <= f[i] && entra){
                f[i] = f[prev];
                ult[i] = min(ult[i],ult[prev] + w[b]);
            }
            if(f[prev] + 1 <= f[i]){
                f[i] = f[prev] + 1;
                ult[i] = min(ult[i],w[b]);
            }
            }
        }
    }
        cout << f[f.size()-1] << endl;
}
