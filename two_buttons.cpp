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
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> d(10001,-1);
    vector<int> act = {n};
    vector<int> sig;
    int dAct = 0;
    while(!act.empty()){
        for(int x : act){
            if(d[x] != -1){continue;} // si ya lo explore
            d[x] = dAct;
            vector<int> con{x * 2, x -1};
            for(int c : con ){
                if(c >= 0 && c <= 10000 && d[c] == -1){
                    sig.pb(c);
                }
            }
        }
        dAct++;
        act.clear();
        swap(act,sig);
    }
    cout << d[m] << endl;
}
