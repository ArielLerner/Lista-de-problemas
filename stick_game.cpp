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
vector<int> p;
vector<bool> is_win;
int main(){
    //freopen("stdin.txt","r",stdin);
    int n,k; cin >> n >> k;
    forn(i,k){
        int x; cin >> x;
        p.pb(x);
    }
    is_win.resize(n+1);
    is_win[0] = false;
    forn(i,sz(is_win)){
        bool win = false;
        for(int x : p){
            if(x > i){continue;}
            win = win | (!is_win[i-x]);
        }
        is_win[i] = win;
    }
    string ans(n,'L');
    forr(i,1,n+1){
        if(is_win[i]){ans[i-1] = 'W';}
    }
    cout << ans << endl;
}
