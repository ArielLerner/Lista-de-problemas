// codigo del verano de 2025
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >= a; i--)
#define dforn(i,n) dforr(i,0,n)
#define all(x) x.begin(),x.end()
#define sz(a) a.size()
using namespace std;
using par = pair<int,int>;
using ll = long long int;
using hashmap = unordered_map<int,int>;
using matriz = vector<vector<int>>;
matriz c;
vector<int> visited;
vector<int> path;
int dfs(int n, int ind){
    path[ind] = n;
    if(visited[n] == 1){return ind;}
    visited[n] = 1;
    for(int con : c[n]){
        if(visited[con] != 2){
            int r = dfs(con,ind+1);
            if(r != -1){return r;}
        }
    }
    visited[n] = 2;
    return -1;
}
int main(){
   //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n; cin >> n;
    c.resize(n);
    visited.resize(n,0);
    path.resize(n);
    int m; cin >> m;
    forn(i,m){
        int a,b;
        cin >> a;
        cin >> b;
        a--;
        b--;
        c[a].push_back(b);
    }
    forn(i,n){
        if(!visited[i]){
            int ans = dfs(i,0);
            if(ans != -1){
                int rep =  path[ans];
                int count = 0;
                vector<int> realPath;
                forn(i,path.size()){
                    if(path[i] == rep){count++;}
                    if(count == 1){
                        realPath.push_back(path[i]+1);
                    }
                }
                realPath.push_back(rep+1);
                cout << realPath.size() << endl;
                for(int x : realPath){
                    cout << x << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
