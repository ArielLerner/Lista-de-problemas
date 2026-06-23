
// backtracking usado para sacar el 10 x 10
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int n = 10;
int used[n][n]; // guardo cual use
int cx[n][n]; // conexiones hacia arriba
int cy[n][n]; // conexiones hacia la izq
int freq[5];
bool can[5];
int num[3] = {1,2,4};
int best[n][n];
int ans = -100;
int id = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void copy(){
    forn(x,10){ 
        forn(y,10){
            best[x][y] = used[x][y];
        }
    }
}
int cnt = 0;
int cnt2 = 0;
void print(){
    forn(x,10){
        cout << "{";
        forn(y,10){
            cout << best[x][y] << ", ";
        }
        cout << "}, " << endl; 
    }
    cout << endl;
    cout << "count : " << cnt / 30000 << endl;
    cout << "count2: " << cnt2 << endl;
    cout << "-------------------------" << endl;
}
    int i = 100;
    int i2 = 8;
    int i3 = 0;
void back(int x, int y , int v){
    id++;
    if(id == 5e8){
        id = 0;
        print();
    }
    // chequeo si se puede // usando un grafo
    // creo las conexiones
    int mask = 0;
    cx[x][y] = cy[x][y] = 0;
    forn(i,x){
        if(used[i][y] == v){
            cx[x][y] += (1 << i);
            mask = mask | (cy[i][y]);
        }
    }
    forn(i,y){
        if(used[x][i] == v){
            cy[x][y] += (1 << i);
        }
    }
    mask = mask & cy[x][y];
    //
    if(mask != 0){return;} // si hay cuadrado devuelvo

    if(x + y >= 16){cnt++;}
    if(x + y >= 17){cnt2++;}

    // si pasa hasta aca es porque es valido
    used[x][y] = v;
    if(x + y > ans){     // me fijo si es la mejor rta posible
        copy();
        ans = x + y;
    } 
    if(x == 9 && y == 9){return;} // ans
    freq[v]++;
    // expando
    int sigX,sigY;    
    if(y+1 < x){
        sigX = x;
        sigY = y+1;
    }
    else if(y < x){
        sigX = 0;
        sigY = x;
    }
    else if(x < y){
        sigX = x + 1;
        sigY = y;
    }
    else{
        // si x es igual a y
        sigX = x + 1;
        sigY = 0;
    }
    can[1]  = freq[1] <= freq[2]+i  && freq[1] <= freq[4]+i;
    can[2]  = freq[2] <= freq[1]+i2  && freq[2] <= freq[4]+i2;
    can[4]  = freq[4] <= freq[2]+i3  && freq[4] <= freq[1]+i3;
    int orden[3] = {1, 2, 4};
    shuffle(orden, orden + 3, rng);
    for(int v : orden){
        // tengo que optimizar para que distribuya
        if(can[v] || y == 9){
            back(sigX,sigY,v);
        }
    }
    freq[v]--;
}
int main(){
    srand(time(0));
    back(0,0,1);
    print();
}
