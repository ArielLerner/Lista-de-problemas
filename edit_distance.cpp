// del verano de 2025
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
using namespace std;
using ll = long long int;
int maxi = 10000;
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    string initial, to;
    cin >> initial;
    cin >> to;
    vector<vector<int>> f(initial.size() + 1,vector<int>(to.size() + 1,maxi)); // f[initial][to]
    forn(i,to.size() + 1){
        f[initial.size()][to.size()- i] = i; // basicamente es hacer replaces al principio
    }
    dforn(pos,initial.size()){
        dforn(priHecho,to.size() + 1){
            // insert
            if(priHecho + 1 <= to.size()){
                f[pos][priHecho] = min(f[pos][priHecho],f[pos][priHecho + 1] + 1);
            }
            // remove
            f[pos][priHecho] = min(f[pos][priHecho],f[pos + 1][priHecho] + 1);
            // replace
            if(priHecho >= to.size() || pos >= initial.size()){continue;}
            if(initial[pos] == to[priHecho]){
                f[pos][priHecho] = min(f[pos][priHecho],f[pos + 1][priHecho + 1]);
            }
            else{
                f[pos][priHecho] = min(f[pos][priHecho],f[pos + 1][priHecho + 1] + 1);  
            }
        }
    }
    cout << f[0][0] << endl;
}
