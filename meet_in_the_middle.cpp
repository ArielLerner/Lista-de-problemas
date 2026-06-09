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
unordered_map<ll,ll> s1,s2; // number , ways
ll ans = 0;
ll x;
void calculateSums(vector<int> &a,unordered_map<ll,ll> &s, bool insert, unordered_map<ll,ll> &op){
    int lg2 = sz(a);
    int t = (1 << lg2);
    vector<ll> bm(t);
    forn(i,t){
        ll sum = 0;
        forn(bit,lg2){
            if(i & (1 << bit)){
                bm[i] = bm[i - (1 << bit)] + a[bit];
                break;
            }
        }
    }
    for(ll act: bm){
        if(insert){
            s[act]++;
        }
        else{
            ll comp = x - act;
            auto it = op.find(comp);
            if(it == op.end()){continue;}
            ans += it->second; 
        }
    }
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    vector<int> n1;
    vector<int> n2;
    ll n; cin >> n >> x;
    forn(i,n){
        int x; cin >> x;
        if(i % 2 == 0){n1.pb(x);}
        else{n2.pb(x);}
    }
    calculateSums(n1,s1,true,s1);
    calculateSums(n2,s2,false,s1);
    cout << ans << endl;
}
