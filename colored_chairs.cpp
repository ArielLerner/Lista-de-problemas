#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = b-1; i >=a;i--)
#define dforn(i,n) dforr(i,0,n)
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using par = pair<int,int>;
using ll = long long int;
using matriz = vector<vector<int>>;

bool val(char x){
    if(x == 'R'){return false;}
    if(x == 'B'){return true;}
}
bool query(int x){
    cout << "? " << x + 1 << endl;
    cout.flush();
    char ch; cin >> ch;
    return val(ch);
}
void rta(int x){
    cout << "! " << x+1 << endl;
}
int main(){
    int n; cin >> n;
    bool vL = query(0);
    bool vR = (query(n-1));
    if(vL == vR){
        rta(n-1);
        return 0;
    }
    int L = 1;
    int R = n-2;
    vector<int> val(n,-1);
    val[0] = vL;
    val[n-1] = vR;
    while(L != R){
        int m = (L + R) / 2;
        bool vm = query(m);
        val[m] = vm;
        if( (vL + m) % 2 == vm){ // si vm concuerda con 0
            L = m+1;
        }
        else{
            R = m-1;
        }
    }
    if(val[L] == -1){
        val[L] = query(L);
    }
    forn(i,sz(val)-1){
        if(val[i] != -1 && val[i] == val[i+1]){
            rta(i);
            break;
        }
    }
}
