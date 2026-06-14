#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i < (b); i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (b-1); i >= (a); i--)
#define dforn(i,n) dforr(i,0,n)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(i) i.size()
using namespace std;
using ll = long long int;
using par = pair<int,int>;
int sz_cc(int i , vector<vector<int>> &ady, vector<bool> &done){
    done[i] = true;
    int ans = 1;
    for(int c : ady[i]){
        if(!done[c]){
            ans+= sz_cc(c,ady,done);
        }
    }
    return ans;
}
bool solve(){
    int n; cin  >> n;
    vector<vector<int>> ady(n);
    vector<int> q(n);
    forn(i,n){
        int a,b; cin >> a >> b;
        a--;b--;
        ady[a].pb(b);
        ady[b].pb(a);
        q[a]++;
        q[b]++;
    }
    forn(i,sz(q)){
        if(q[i] != 2){return false;}
    }
    vector<bool> done(n);
    forn(i,n){
        if(!done[i]){
            if(sz_cc(i,ady,done) % 2 == 1){
                return false;
            }
        }
    }
    return true;
}
int main(){
    //freopen("C:/Users/Gamer/OneDrive/Escritorio/OIA/codeforces/stdin.txt","r",stdin);
    int t; cin >> t;
    while(t--){
        bool ans = solve();
        if(ans){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
