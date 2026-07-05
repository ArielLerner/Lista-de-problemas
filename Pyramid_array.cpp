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
#define  par  pair<int,int>
using namespace std;
vector<int> tree;
int priN;
void plus1(int i){
    i+= priN;
    while(i > 0){
        tree[i] += 1;
        i /=2;
    }
}
int sum(int R){
    R+= priN;
    int L = priN;
    int ans = 0;
    while(L <= R){
        if((L % 2) == 1){
            ans += tree[L];
            L++;
        }
        if((R % 2) == 0){
            ans += tree[R];
            R--;
        }
        R = R/2;
        L = L/2;
    }
    return ans;
}
int main(){
    //freopen("stdin.txt","r",stdin);
    int n; cin  >> n;
    vector<par> v(n);
    // sg tree
    int l2 = ceil(log2(n))+1;
    int t = (1 << l2);
    priN = t/2;
    tree.resize(t,0);

    forn(i,n){
    cin >> v[i].first;
    v[i].second = i;
    }
    sort(v.begin(),v.end(),std::greater<par>());
    // voy metiendo los indexes
    ll ans = 0;
    forn(tot,n){
        int i = v[tot].second;
        ll pref = sum(i);
        ll suf = tot - pref;
        ans += min(suf,pref);
        plus1(i);
    }
    cout << ans << endl;
}
