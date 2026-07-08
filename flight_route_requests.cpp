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
vector<vector<int>> to;
vector<vector<int>> from;
void ex_toposort(deque<int> &topo, int i, vector<bool> &explored, set<int> &to_exp){
    explored[i] = true;
    for(int x : to[i]){
        if(explored[x]){continue;}
        ex_toposort(topo,x,explored,to_exp);
    }
    topo.push_front(i);
    for(int x : from[i]){
        if(explored[x]){
            continue;
        }
        to_exp.insert(x);
    }
}
int main(){
   // freopen("stdin.txt","r",stdin);
    int n,m; cin >> n >> m;
    to.resize(n);
    from.resize(n);
    forn(i,m){
        int a,b; cin >> a >> b;
        a--;b--;
        to[a].pb(b);
        from[b].pb(a);
    }
    vector<bool> exp, ins;
    exp = ins = vector<bool>(n);
    int ans = 0;
    vector<bool> proces(n);
    forn(i,n){
        if(exp[i]){continue;}
        deque<int> comp;
        set<int> to_exp;
        ex_toposort(comp,i,exp,to_exp);
        while(!to_exp.empty()){
            int x = *to_exp.begin();
            to_exp.erase(to_exp.begin());
            if(exp[x]){continue;}
            ex_toposort(comp,x,exp,to_exp);
        }
        ans+= sz(comp)-1;
        bool dag = true;
        for(int x: comp){
            for(int c : to[x]){
                if(proces[c]){dag = false;}
            }
            proces[x] = true;
        }
        if(!dag){ans++;}
    }
    cout << ans << endl;
}
