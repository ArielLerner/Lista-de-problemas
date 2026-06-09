// Este problema lo habia visto hace como 6 meses
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
void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> dp(k+1,vector<int>(k+1)); // dp[i][kUsed] = max sum til  i, with at most k 
    int mayor = 0;
    forn(i,n){
        cin >> a[i];
        if(a[i] <= mayor){continue;}
        forr(kn,mayor+1,a[i]+1){ // combino un nuevo k con un k viejo
            forn(ko,mayor+1){
                forn(useP,k + 1 - kn){
                    int ans = dp[ko][useP] + (kn - ko) * (n - i);
                    dp[kn][useP + kn] = max(dp[kn][useP+kn],ans);
                }
            }
        }
        mayor = a[i];
    }
    int rta = 0;
    forn(x,k+1){
        forn(y,k+1){
            rta = max(rta,dp[x][y]);
        }
    }
    cout << rta << endl;
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int t; cin >> t;
    while(t--){
        solve();    
    }
}
