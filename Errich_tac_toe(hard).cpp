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
pair<int,vector<string>> costo(char a, int modA, char b, int modB, int n, vector<string> m){
    // recorro las diagonales y las numero
    // aquellas diagonales como  (i % 3) == modA 
    //las lleno de char A y con b lo mismo...
    int costo = 0;
    forn(d, 2 * n){
        forn(delta, 2 * n){
            int x = d -delta;
            int y = delta;
            if(x < 0 || x >= n){continue;}
            if(y < 0 || y >= n){continue;}
            // si llega aca es posicion valida
            if(m[x][y] == '.'){continue;} // si es punto no modifico
            int mod = d % 3;
            if(mod == modA && m[x][y] == b){
                costo++;
                m[x][y] = a;
            }
            if(mod == modB && m[x][y] == a){
                costo++;
                m[x][y] = b;
            }
        }
    }
    return pair<int,vector<string>>(costo,m);
}
void solve(){
    int n; cin >> n;
    vector<string> m(n);
    forn(i,n){
        cin >> m[i];
    }
    char a = 'X';
    char b = 'O';
    pair<int,vector<string>> ans;
    forn(i,3){
        int modA = i;
        int modB = (i + 1) % 3;
        pair<int,vector<string>> act = costo(a,modA,b,modB,n,m);
        if(i == 0){ans = act; continue;}
        if(act.first < ans.first){ans = act;}
    }
    for(string s : ans.second){
        cout << s << endl;
    }
    return;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
