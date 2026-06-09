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
vector<vector<bool>> libre;
ll ans = 0;
vector<vector<int>> atacked(8,vector<int>(8,0));
#define atroden(i) ((i) >= 0 && (i) < 8)
void sumarAtacked(int x, int y, int v){
    atacked[x][y]+=v;
    forr(dx,-1,2){
        forr(dy,-1,2){
            if(dx == 0 && dy == 0){continue;}
            int x2 = dx + x;
            int y2 = dy + y;
            while(atroden(x2) && atroden(y2)){
                atacked[x2][y2]+=v;
                x2 += dx;
                y2 += dy;
            }
        }
    }
}
void buscar(int p , int xp){
    if(p == 9){ans++;return;}
    forr(x,xp+1,8){
        forn(y,8){
            if(libre[x][y] && !atacked[x][y]){
                sumarAtacked(x,y,1);
                buscar(p+1,x);
                sumarAtacked(x,y,-1);
            }
        }
    }
}
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);

    libre = vector<vector<bool>>(8,vector<bool>(8,0));
    forn(x,8){
        forn(y,8){
            char ch; cin >> ch;
            if(ch == '.'){libre[x][y] = true;}
        }
    }
    buscar(1,-1);
    cout << ans << endl;
}
