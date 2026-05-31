 // Mountain Range: Solución de diciembre de 2025. 


#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
using namespace std;
using par = pair<int,int>;
vector<int> maxi;
vector<int> pos;
int priN;
void inicializar(vector<int> &nros){
   int l2 = ceil(log2(nros.size()));
   int t = (1 << (l2 + 1));
   priN = t/2;
   maxi.assign(t,-1);
   pos.assign(t,-1);
   forn(i,nros.size()){
       maxi[i + priN] = nros[i];
       pos[i + priN] = i;
   }
   dforn(i,priN){
       if(maxi[2 * i] > maxi[2 * i + 1]){
           maxi[i] = maxi[2 * i];
           pos[i] = pos[2 * i];
       }
       else{
           maxi[i] = maxi[2 * i + 1];
           pos[i] = pos[2 * i + 1];
       }
   }
}
par query(int l,int  r){
   int maximo = -1;
   int ind = -1;
   l += priN; r += priN;
   while( l <= r){
       if( l % 2 == 1){
           if(maxi[l] > maximo){
               maximo = maxi[l];
               ind = pos[l];
           }
           l ++;
       }
       if(r % 2 == 0){
           if(maxi[r] > maximo){
               maximo = maxi[r];
               ind = pos[r];
           }       
           r--;
       }
       l = l / 2;
       r = r / 2;
   }
   return par(maximo,ind);
}
vector<int> nros;
int solucion(int l, int r, int ultValor){
   // tengo que buscar el mayor
   // despues tengo que buscar el maximo entre las dos soluciones hijas
   // y devuelvo el mayor
   if(l == r && nros[l] != ultValor){return 1;}
   if(l > r){return 0;}
   par maximo = query(l,r);
   int suma = 1;
   if(maximo.first == ultValor){suma = 0;}
   int s1 = solucion(l,maximo.second - 1,maximo.first);
   int s2 = solucion(maximo.second + 1,r,maximo.first);
   return max(s1,s2) + suma;
}
int main(){
       //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
   int n; cin >> n;
   nros.resize(n);
   forn(i,n){cin >> nros[i];}
   inicializar(nros);
   vector<par> copyN(n);
   forn(i,n){
       copyN[i] = par(nros[i],i);
   }
   std::sort(copyN.begin(),copyN.end(),std::greater<par>());
   // lo ordeno de mayor a menor
   cout << solucion(0,nros.size()-1 ,1e9 + 10);
}
