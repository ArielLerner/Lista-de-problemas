#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i < (b); i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (b) -1 ; i >= (a); i--)
#define dforn(i,n) dforr(i,0,n)
#define pb push_back
#define sz(i) i.size()
#define dbg(x) cerr << #x << ":  " << x << endl
#define all(x) x.begin(),x.end()
using ll = long long int;
using namespace std;
vector<vector<int>> psum, p,ch,minX,minY;
void rect_sum(int szX, int szY, vector<vector<int>> &s){
    forn(y,sz(s[0]) - szY + 1){
        int lastY = y + szY - 1;
        int suma = 0;
        // este es el resultado del [x][y]
        forn(x,szX){
            suma += psum[x][lastY];
            if(y > 0){suma -= psum[x][y-1];}
        }
        s[0][y] = suma;
        forr(x,1,sz(s) - szX + 1){
            int sacar;
            if(y > 0){
                sacar = psum[x-1][lastY] - psum[x-1][y-1];
            }
            else{
                sacar = psum[x-1][lastY];
            }
            int x_push = x + szX -1;
            int newV = psum[x_push][lastY];
            if(y > 0){newV -= psum[x_push][y-1];}
            suma += newV - sacar;
            s[x][y] = suma;        
        } 
    }
}
struct sw_rmq{
    // guardo el mas viejo en el front
    // guardo el mas nuevo en el back
    deque<int> v;
    deque<int> t;
    int R;
    vector<int> src;
    sw_rmq(vector<int> &s){
        R = 0;
        src = s;
    }
    void borrar_back(){
        v.pop_back();
        t.pop_back();
    }
    void borrar_front(){
        v.pop_front();
        t.pop_front();
    }
    void insertar(int i){
        while(R <= i){
            while(!v.empty() && v.back() >= src[R]){
                borrar_back();
            }
            v.pb(src[R]);
            t.pb(R);
            R++;
        }
    }
    void borrar(int time){
        while(!v.empty() && t.front() <= time){
            borrar_front();
        }
    }
    int minimo(){
        if(v.empty()){return -1;}
        return v[0];
    }
};
vector<int> solve(int n, int m, int a, int b, int c, int d){
    p = ch = minX = minY =  vector<vector<int>>(n,vector<int>(m,0));
    rect_sum(a,b,p);
    rect_sum(c,d,ch);
    // ahora calculo el mejor chamber
    int xFinal = n - a + 1;
    int yFinal = m - b + 1;
    forn(x,n - c + 1){
        // hago un sliding window rmq
        sw_rmq sl(ch[x]);
        // voy determinando el y
        forn(y,m - d + 1){
            int R  = sl.R;
            while(R + d <= y + b - 1 && R < m){
                sl.insertar(R);
                R++;
            }
            sl.borrar(y);
            minY[x][y] = sl.minimo();
        }
    }
    int v = -1e9;
    int mx,my;
    forn(y,yFinal){
        // creo el vector de sliding window
        vector<int> sr(n);
        forn(x,n){sr[x] = minY[x][y];}
        sw_rmq sl(sr);
        forn(x,xFinal){
            int R = sl.R;
            while(R + c <= x + a -1 && R < n){
                sl.insertar(R);
                R++;
            }
            sl.borrar(x);
            minX[x][y] = sl.minimo();
            if(p[x][y] -  (minX[x][y]) > v){
                v = p[x][y] - minX[x][y];
                mx = x; my = y;
            } 
        }
    }
    // ya tengo el primer valor ahora hago una busqueda para encontrar el segundo
    int vc = minX[mx][my];
    int x2,y2;
    x2 = y2 = -2;
    forr(x,mx+1,mx +a){
        forr(y,my+1,my + b ){
            if(x + c > mx + a - 1){continue;}
            if(y + d > my + b  -1){continue;}
            if(vc == ch[x][y]){
                x2 = x; y2 = y;
                break;
            }
        }
    }
    return vector<int> {my+1,mx+1,y2+1,x2+1};
}
int get(int may){
    return (rand() % may) + 1;
}
int sum(vector<vector<int>> &v, int x0, int xf, int y0, int yf){
    int suma = 0;
    forr(x,x0,xf+1){
        forr(y,y0,yf+1){
            suma += v[x][y];
        }
    }
    return suma;
}
int main(){
    //freopen("stdin.txt","r",stdin);
    int n,m,a,b,c,d;
    cin >> m >> n >> b >> a >> d >> c;
    vector<vector<int>> v(n,vector<int>(m));
    psum.assign(n,vector<int>(m));

    forn(x,n){
        forn(y,m){
            cin >> v[x][y];
            if(y == 0){
                psum[x][y] = v[x][y];
            }
            else{
                psum[x][y] = psum[x][y-1] + v[x][y];
            }
        }
    }
    vector<int> r  = solve(n,m,a,b,c,d);
    cout << r[0] << " " << r[1] << endl;
    cout << r[2] << " " << r[3] << endl;
}
