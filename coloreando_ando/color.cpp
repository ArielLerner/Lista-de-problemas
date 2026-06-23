
// backtracking para c = 2
// output only para c = 3
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

// pasteo el backtracking para hacer directo cuando c = 2;

const int n = 10;
int used[n][n]; // guardo cual use
int cx[n][n]; // conexiones hacia arriba
int cy[n][n]; // conexiones hacia la izq
int freq[5];
bool can[5];
int num[2] = {1,2};
int best[n][n];
int ans = -100;
void copy(){
    forn(x,10){ 
        forn(y,10){
            best[x][y] = used[x][y];
        }
    }
}
int maxX, maxY;
void back(int x, int y , int v){
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
    // si pasa hasta aca es porque es valido
    used[x][y] = v;
    if(x == maxX-1 && y == maxY-1){
        copy();
        return;
    } // ans
    freq[v]++;
    // expando
    int sigX = x;
    int sigY = y + 1;
    if(sigY == maxY){
        sigX = x + 1;
        sigY = 0;
    }
    for(int v : num){
        // tengo que optimizar para que distribuya
            back(sigX,sigY,v);
    }
    freq[v]--;
}
int main(){
    vector<vector<int>> ans3{
    {1, 2, 4, 2, 1, 2, 4, 2, 1, 4, },
    {2, 4, 2, 4, 1, 2, 1, 1, 4, 2, },
    {2, 1, 1, 2, 1, 4, 2, 4, 4, 4, },
    {1, 4, 4, 2, 2, 1, 1, 4, 2, 2, },
    {2, 2, 1, 4, 4, 1, 4, 4, 2, 1, },
    {1, 4, 1, 1, 4, 2, 2, 1, 2, 4, },
    {4, 2, 2, 4, 2, 1, 2, 1, 1, 4, },
    {4, 1, 4, 1, 4, 1, 2, 2, 4, 2, },
    {2, 1, 4, 4, 2, 4, 1, 2, 1, 1, },
    {4, 4, 2, 1, 1, 4, 4, 2, 2, 1, }
    };
    int c; cin >> maxX >> maxY >> c;
    if(c == 2){
        back(0,0,1);
    }
    forn(x,maxX){
        forn(y,maxY){
            if(c == 3){
                int v = ans3[x][y];
                if(v == 4){v = 3;}
                cout << v << " ";
            }
            if(c == 2){
                cout << best[x][y] << " ";
            }
        }
        cout << endl;
    }
}
