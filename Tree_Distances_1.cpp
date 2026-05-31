// solucion de diciembre de 2025
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
using namespace std;
vector<vector<int>> c;
vector<int> maxDist;
vector<int> maxToHijos;
vector<int> segMax;
int maximoToHijo(int n, int padre){
    int maximo = 0; int iMax = -1;
    int minimo = 0;
    for(int hijo : c[n]){
        if(hijo == padre){continue;}
        int hastaHijo = maximoToHijo(hijo,n) +1;
        if(hastaHijo > maximo){minimo = maximo; maximo = hastaHijo; iMax = hijo;}
        else{
            if(hastaHijo > minimo){minimo = hastaHijo;}
        }
    }
    maxToHijos[n] = maximo;
    segMax[n] = minimo;
    return maximo;
}
void maxTotal(int n, int padre, int maxDistPadre){
    bool aPadre = false;
    if(n == 0){
        maxDist[n] = maxToHijos[n];
    }
    else{
        if(maxDistPadre > maxToHijos[n]){
            aPadre = true;
            maxDist[n] = maxDistPadre;
        }
        else{
            maxDist[n] = maxToHijos[n];
        }
    }
    for(int hijo : c[n]){
        if(hijo == padre){continue;}
        if(!aPadre && maxDist[n] == maxToHijos[hijo] + 1){ // si viene del hijo
            maxTotal(hijo,n,max(maxDistPadre + 1, segMax[n] + 1));
        }
        else{
            maxTotal(hijo,n,maxDist[n] + 1);
        }
    }
}
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n; cin >> n;
    c.resize(n);
    maxDist.resize(n,0);
    maxToHijos.resize(n,0);
    segMax.resize(n,0);
    forr(i,1,n){
        int a,b;
        cin >> a; a--;
        cin >> b; b--;    
        c[a].push_back(b);
        c[b].push_back(a);
    }
    maximoToHijo(0,-1);
    maxTotal(0,-1,0);
    for(int d : maxDist){
        cout << d << " ";
    }
    cout << endl;
}
