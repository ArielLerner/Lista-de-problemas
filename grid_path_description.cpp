// mi idea es hacer recursive backtracking y cuando hay una bifurcacion clara, corto
#pragma GCC optimize("O3,unroll-loops")
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
int ans = 0;
int active = 0;
int delta;
bool used[7][7];
int q[48];
par con[7][7][4];
int prof = 0;
int dx[4]  = {-1,+1,0,0};
int dy[4] = {0,0,-1,+1};
inline bool existe(int x, int y){
    if(x >= 0 && y >= 0 && x <= 6 && y<= 6){return true;}
    return false;
}
void iniciarCon(){
    forn(x,7){
        forn(y,7){
            forn(i,4){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(existe(newX,newY)){
                   con[x][y][i] = par(newX,newY);
                }
            }  
        }
    }
}
void back(int x, int y){
    if( x == 6 && y == 0){
        if(prof == 48){ans++;}
        return;
    }
    delta = 0;
    forn(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(existe(nx,ny) && !used[nx][ny]){
                if(nx != x){delta++;}
                if(ny != y){delta--;}
            }
    }
    if(abs(delta) == 2){return;}
    // si pasa, entonces sigo la recursion
    used[x][y] = true;
    prof++;
    if(q[prof-1] == 4){
        forn(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(existe(nx,ny) && !used[nx][ny]){
                back(nx,ny);
            }
        } 
    }
    else{
        int index = q[prof-1];
        int newX = x + dx[index];
        int newY = y + dy[index];
        if(existe(newX,newY) && !used[newX][newY]){
            back(newX,newY);
        }
    }
    prof--;
    used[x][y] = false;
}
int main(){
    iniciarCon();
    forn(i,48){
        q[i] = 4;
        char x; cin >> x;
        if(x == 'U'){q[i] = 0;}
        if(x == 'D'){q[i] = 1;}
        if(x == 'L'){q[i] = 2;}
        if(x == 'R'){q[i] = 3;} 
    }
    back(0,0);
    cout << ans << endl;
}
