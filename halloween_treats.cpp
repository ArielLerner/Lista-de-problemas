// me spoilee la solucion lamentablemente
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
void solve(int c,int n){
    vector<int> ac(n);
    map<int,int> m;
    int st,end;
    vector<int> x(n);
    forn(i,n){cin >> x[i];}
    ac[0] = x[0];
    m[ac[0]] = 0;
    forr(i,1,n){
        ac[i] = (ac[i-1] + x[i]) % c;
        if(ac[i] == 0){
            st = 0; end = i;
            break;
        }
        if(m.count(ac[i])){
            st = m[ac[i]]+1;
            end = i;
            break;
        }
        m[ac[i]] = i;
    }
    forr(i,st,end+1){
        cout << i+1 << " ";
    }
    cout << endl;
}
int main(){
    while(true){
        int c,n; cin >> c >> n;
        if(c == 0){break;}
        solve(c,n);
    }
}
