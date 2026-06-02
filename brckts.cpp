
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using par = pair<int,int>;
using ll = long long int;
using matriz = vector<vector<int>>;
vector<int> tree; // contando la suma parcial
vector<int> izq; 
vector<int> der;
vector<int> sum;
int priN;
void sumaT(int L, int R, int v, int p){
    int tl = izq[p]; int tr = der[p];
    if(L <= tl && tr <= R){
        tree[p] += v;
        sum[p]+=v;
        return;
    }
    if(tr < L || R < tl){return;}
    sumaT(L,R,v, 2 * p);
    sumaT(L,R,v,2 * p + 1);
    tree[p] = min(tree[2 * p],tree[2 * p + 1]) + sum[p];
}
vector<bool> solve(int n, string &s , vector<int> &q){
    if(n == 0){return {};}
    vector<int> val(n,-1);
    forn(i,sz(s)){
        if(s[i] == '('){
            val[i] = 1;
        }
    }
    vector<int> ps(n);
    ps[0] = val[0];
    forr(i,1,sz(ps)){ // calculo prefix sum
        ps[i] = ps[i-1] + val[i];
    }
    int l2 = ceil(log2(2 * n));
    int t = (1 << l2);
    izq = der = sum = vector<int>(t,0);
    tree.assign(t,1e9);
    priN = t/2;
    /// tengo que chequear tambien que hay igual cantidad de abiertos que cerrados
    forn(i,priN){
        if(i < sz(ps)){
            tree[i + priN] =ps[i];
        }
        izq[i + priN] = der[i + priN] = i; 
    }
    dforr(i,1,priN){
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        izq[i] = izq[2 * i];
        der[i] = der[2 * i + 1];
    }
    int delta = ps[n-1];
    int m = sz(q);
    vector<bool> ans;
    for(int k : q){
        if(k == 0){
            if( (n % 2) == 0 && delta == 0 && tree[1] >= 0 ){
                cout << "YES" << endl;
                ans.pb(1);
            }
            else{
                cout << "NO" << endl;
                ans.pb(0);
            }
        }
        if(k > 0){
            k--;
            int suma;
             if(val[k] == -1){
                suma = 2;
                delta+=2;
             }
             else{
                suma = -2;
                delta-=2;
             }
             val[k] = val[k] * -1;
            sumaT(k,n-1,suma,1);
        }
    }
    return ans;
}
// le hice un evaluador porque me daba wrong answer, pero era porque no imprimia el test i en el output
/*
void testCase(int t, int tam, int m){
    srand(time(0));
    while(t--){
        string s;
        vector<bool> correct;
        vector<int> arr(tam);
        forn(i,tam){
            int r = rand() % 2;
            s.pb('(' + r);
            if(!r){arr[i] = 1;}
            else{arr[i] = -1;}
        }
        vector<int> q;
        forn(i,m){
            int r = rand() % 3;
            if(r == 0){
                q.pb(0);
                // evaluo el prefix aca
                // condiciones 1. siempre mayor o igual a 0, 2. el ultimo debe ser 0
                bool great0 = true;
                int delta = 0;
                for(int x : arr){
                    delta+=x;
                    if(delta < 0){great0 = false; break;}
                }
                if(great0 && delta == 0){
                    correct.pb(true);
                }
                else{
                    correct.pb(false);
                }
                continue;
            }
            r =  ( rand() % tam ) + 1 ;
            q.pb(r);
            arr[r-1] *= -1;
        }
        vector<bool> ans =  solve(tam,s,q);
        // ahora debo chequear que este bien
        forn(i,sz(correct)){
            if(correct[i] !=  ans[i]){
                cout << "MAL" << endl;
            }
        }
    }
}
int main(){
    testCase(1000,12,1000);
}
*/
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int t = 10;
    forn(i,t){
        int n; cin >> n;
        string s; cin >> s;
        int m; cin >> m;
        vector<int> q(m);
        forn(i,m){cin >> q[i];}
        cout << "Test " << i+1 << ":" << endl;
        solve(n,s,q);
    }
}
  
