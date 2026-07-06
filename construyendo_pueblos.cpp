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
using par = pair<ll,vector<int>>;
vector<par> trie;
int id = 1;
int sigNodo(int i, char ch){
    int s = ch-'0';
    if(trie[i].second[s] == -1){
        trie[i].second[s] = id++;
    }
    return trie[i].second[s];
}
void inicializar(int Q,int M)
{
    trie.assign(Q * M + 100, par(0,vector<int>(10,-1)));
}
ll change(string &to, int p, int i, ll newV){
    // devuelvo el delta que hay que cambiar
    if(p == sz(to)-1){
        ll delta = newV - trie[i].first;
        trie[i].first = newV;
        return delta;
    }
    int sig = sigNodo(i,to[p+1]);
    ll delta = change(to,p+1,sig,newV);
    trie[i].first += delta;
    return delta;
}
long long pueblo(string A, long long PA)
{
    ll delta = change(A,-1,0,PA);
    ll old = (delta - PA) * -1;
    return old;
}
ll sum(string &A , string &B, bool preB , bool postA, int p, int i, int lastD){
    int dl,dr;
    dl = dr = 0;
    if(p >= 0){
        dl = A[p] - '0';
        dr = B[p] - '0';
    }
    bool a = postA | dl <= lastD;
    bool b = preB | lastD <= dr; 
    // hacer caso final si p es size -1
    if(p == sz(A)-1){
        if(a & b ){return trie[i].first;}
        return 0;
    }
    //
    bool mid = (postA | dl < lastD) & (preB | lastD < dr);
    if(mid){return trie[i].first;}
    if((!a) | (!b)){return 0;}
    ll ans = 0;
    forn(d,10){
        if(trie[i].second[d] == -1){continue;}
        bool preB_2 = preB | (d < (B[p+1] - '0'));
        bool postA_2 = postA |  (d > (A[p+1] - '0'));
        ans += sum(A,B,preB_2,postA_2,p+1,trie[i].second[d],d);
    }
    return ans;
}
long long consulta(string A, string B)
{
    return sum(A,B,false,false,-1,0,0);
}
