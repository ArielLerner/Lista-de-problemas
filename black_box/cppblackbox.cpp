#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,fma")
#include <iostream>
#include <vector>
#include "cppbblib.h"
#include <fstream>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define sz(i) i.size()
#define pb push_back
#define all(i) i.begin(), i.end()
#define dbg(x) cout << #x << " " << x << endl;
using namespace std;
using par = pair<int,int>;
using box = vector<string>;
void barra(){
    cout << "------------------------" << endl;
}
par mas(par &a, par &b){
    return par(a.first + b.first, a.second + b.second);
}
int n;
int t = 1;
int r = 2;
int d = 3;
int l = 4;
box ans, act;
char punto = '.';
char on = '\\';
char off = '/';
int opuesto[] =  {-1,d,l,t,r};
int switchOn[]  = {-1, l, d, r, t}; // '\'
int switchOff[] = {-1, r, t, l, d}; // '/'
vector<vector<int>> L;
vector<vector<int>> R;
int nada = -2;
int getL(int x, int y){
	if(L[x][y] != nada){return L[x][y];}
	L[x][y] = -1;
	for(int i = y-1; i >= 0; i--){
		if(act[x][i] == on || act[x][i] == off){
			L[x][y] = i; break;
		}
	}
	return L[x][y];
}
int getR(int x, int y){
	if(R[x][y] != nada){return R[x][y];}
	R[x][y] = -1;
	for(int i =  y+1; i < n; i++){
		if(act[x][i] == on || act[x][i] == off){
			R[x][y] = i; break;
		}
	}
	return R[x][y];
}
void pr(box &b){
    forn(x,n){
        forn(y,n){
            cout << b[x][y];
        }
        cout << endl;
    }
}
#define print_box(b) cout << #b << endl; pr(b); barra();
#define op(side) opuesto[side]
par movi[]{
    par(-1,-1),
    par(-1,0), // top
    par(0,1), //right
    par(1,0), // down
    par(0,-1), // left
};
struct side{
    int x,y,s;
    side(){x = y = s = -1;}
    side(int x2, int y2, int s2){
        x = x2;
        y = y2;
        s = s2;
    }
    
};
void sideP(side si){
	cout << si.x << " " << si.y << endl;
	cout << si.s << endl;
	barra();
}
#define side_print(si) cout << #si << endl; sideP(si);
bool isVert(int x){return (x == 2 || x == 4);}
bool invX = false;
side query(side &in, int &touches) { // transformo la query
	if(invX){
		if(in.s == t){in.s = d;}
		else if(in.s == d){in.s = t;}
		in.x = n-1 - in.x;
	}
    int x = in.x; 
    int y = in.y;
    int s = in.s;
    int hole;
    if(isVert(s)){
        hole = x + 1;
    }
    else{
        hole = y + 1;
    }
    // hago la query
    int side_out, hole_out;
    touches = throwBall(hole,s,hole_out,side_out);
    int xf, yf;
    
    if (side_out == t) {
        xf = 0;
        yf = hole_out - 1;
    }

    if (side_out == r) {
        yf = n - 1;
        xf = hole_out - 1;
    }

    if (side_out == d) {
        xf = n - 1;
        yf = hole_out - 1;
    }

    if (side_out == l) {
        yf = 0;
        xf = hole_out - 1;
    }
    if(invX){
		xf = n-1-xf;
		if(side_out == t){side_out = d;}
		else if(side_out == d){side_out = t;}
	}
    return side(xf,yf,side_out);
}
char invertir(char ch, bool inv){
    if(ch == '?' || ch == punto || !inv){return ch;}
    if(ch == on){return off;}
    return on;
}
void s_act(){
    forn(x,n){
        forn(y,n){
            act[x][y] = invertir(act[x][y],true);
        }
    }
}
void full_toggle(){
    ToggleDeflectors();
    s_act();
}
void full_reset(){
    ResetBox();
    act = ans;
	return;
}
void add(char c, int x , int y){
    if(c == punto){
        ans[x][y] = act[x][y] = punto;
    }
    else{ // voy a hacer un reset pero por las dudas
        ans[x][y] = act[x][y] =  c;
    }
}
void simulate(box &b, par p, int s, bool save, side &ans , int &cnt,bool is_f){
    // agregar el save
    char c = b[p.first][p.second];
    b[p.first][p.second] = invertir(c,save);
    if(c == '?'){
        ans = side(p.first,p.second,s);
        return;
    }
    par sig;
    if(c != punto){
        cnt++;
        if(c == on && !is_f){
            s = switchOn[s];
        }
        if(c == off && !is_f){
            s = switchOff[s];
		}
    }
    par m = movi[s];
    sig = mas(m,p);
    // if no existe la posicion
    int x = sig.first;
    int y = sig.second;
    if(x < 0 || x >= n || y < 0 || y >= n ){
        ans = side(p.first,p.second,s);
        return;
    }
    //devolver
    simulate(b,sig,s,save,ans,cnt,false);
}
void move_correct(int x , int y){
    // muevo a la izquierda este off
    if(act[x][y] == '?'){return;}
    par in(x,y);
    int cnt = 0;
    side out;
    simulate(act,in,t,false,out,cnt,true);
    side out2;
    par p(out.x,out.y);
    // hago la query para dejarlos iguales
    simulate(act,p,op(out.s),true,out2,cnt,false);
    int c = 0;
    query(out,c);
}
int id = 0;
void set_box(int x, int lastY_On){ // hasta este x setear ceros
    if(x < 0){return;}
    if(lastY_On == n){lastY_On--;}
    forn(i,lastY_On+1){
        if(act[x][i] == off ){
			//barra();
			int y = i;
			while(y >= 0 && y < n ){
				set_box(x-1,y-1);
				move_correct(x,y);	
				y = getL(x,y);
			}
        }
    }
    for(int i = n-1; i >= lastY_On+1; i--){
        if(act[x][i] == on ){
			int y = i;
			while(y >= 0 && y < n){
				set_box(x-1,y);	
				move_correct(x,y);
				y = getR(x,y);
			}
        }
     }
     set_box(x-1,lastY_On);		
}
void solve(int b,bool print_act, bool  full){
	if(!invX){
    n = Initialize(b);
	}
	L = R =  vector<vector<int>>(n,vector<int>(n,-2));
    ans = act  = vector<string>(n,string(n,'?'));
    // aca planteo la solucion
    int nFinal = (n+1)/ 2;
    if(full){nFinal = n;}
    forn(x,nFinal){
        int ly = n;
        forn(i,n){
			if(act[x][i] == on || act[x][i] == off){ly = i;}
		}
        bool quedan = true;
        while(quedan){
			if(print_act){
				print_box(ans);
			}
		full_reset();
            forn(times,2){
            set_box(x,ly);
            side in;
            int exp1,exp2,rta;
            exp1 = exp2 = rta = 0;
            if(ly == n){
				in = side(x,0,l);
                exp1 = 0;
            }
            else{
                side out;
                par p(x,ly);
                simulate(act,p,t,false,in,exp1,true);

                
            }
            // ya cree el punto de salida
            box old = act;
            side out  = query(in,rta);
            if(out.s == d){            
				full_reset();
				full_toggle();
				continue;
            }
            par p = par(out.x,out.y);
            side out2;
            simulate(old,p,op(out.s),false,out2,exp2,false);
            if(ly == n && rta == 0){
				forn(y,n){add(punto,x,y);}
				quedan = false;
				break;
			}
            if(exp1 + exp2 == rta){ // si termine con el x
                quedan = false;
                forn(y,n){
					if(ans[x][y] == '?'){add(punto,x,y);}	
				}
                // agrego todos los puntos que faltan
                full_reset();
                break;
            }
            if(exp1 + exp2 + 1 == rta){ //significa que hay uno en out.x, out.y
                char c = off;
                if(times){c = on;}
                //cout << " importante" << endl;
                add(c,out2.x,out2.y);
                add(c,out2.x,out2.y);
                ly = out2.y;
                // agrego los puntos que faltan
                forn(y,out2.y){
					if(ans[x][y] == '?'){add(punto,x,y);}	
				}
                full_reset();
                bool full = true;
                forn(a,n){
						if(ans[x][a] == '?'){full = false;}
				}
				if(full){
				quedan = false;
				break;
					}
                break;
            }
            //
            full_reset();
            full_toggle();
            }
        }
    }
}

int main() {
    int i = 11;
	std::string name = "out" + std::to_string(i) + ".txt";
	bool in_out = false;
    bool full = false;
	if(in_out){
	std::ofstream file(name);freopen(name.c_str(), "w", stdout);
	}
    if(full){
        solve(i,!in_out,true);
        box fp  = ans;
        print_box(fp);
        Finalize();    
        return 0;
    }
    solve(i,!in_out,false);
    box fp  = ans;  
    invX = true;
    solve(i,!in_out,false);
    box sp = ans;
    forn(x,n){
		forn(y,n){
			char c = fp[x][y];
			if(c == '?'){c = invertir(sp[n-1-x][y],true);}
			cout << c;
		}
		cout << endl;
	}
    Finalize();
}
