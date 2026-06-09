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
multiset<ll> menor;
multiset<ll> mayor;
ll med;
ll L = 0;
ll R = 0;
ll Lsum = 0;
ll Rsum = 0;
void switchR(){
    menor.insert(med);
    Lsum += med;
    L++;
    auto it = mayor.begin();
    med = *it;
    Rsum -= med;
    R--; 
    mayor.erase(it);
}
void switchL(){
    mayor.insert(med);
    Rsum += med;
    R++;
    auto it = prev(menor.end());
    med = *it;
    Lsum -= med;
    L--;
    menor.erase(it);
}
int main(){
    //freopen("C:/Users/Ari/Desktop/Proyectos/C++/input/stdin.txt","r",stdin);
    int n,k; cin >> n >> k;
    vector<ll> e(n);
    forn(i,n){cin >> e[i];}
    med = e[0];
    if(k == 1){cout << 0 << endl;}
    forr(i,1,n){
        // agrego un elemento
        if(e[i] >= med){
            R++;
            Rsum += e[i];
            mayor.insert(e[i]);
        }
        else{
            L++;
            Lsum+= e[i];
            menor.insert(e[i]);
        }
        //saco un elemento
        if(sz(mayor) + sz(menor) + 1 > k){
            ll to_erase = e[i-k];
            if(to_erase == med){
                // hacer el caso
                if(L > 0){
                    auto itL = prev(menor.end());
                    med = *itL;
                    Lsum-= med;
                    L--;
                    menor.erase(itL);
                }
                else{
                    auto it = mayor.begin();
                    Rsum -= *it;
                    med = *it;
                    R--;
                    mayor.erase(it);
                }
            }
            else if(menor.count(to_erase)){
                auto it = menor.find(to_erase);
                Lsum -= *it;
                L--;
                menor.erase(it);
            }
            else if(mayor.count(to_erase)){
                auto it = mayor.find(to_erase);
                Rsum -= *it;
                R--;
                mayor.erase(it);
            }
        }
        // busco la nueva mediana
        while(abs(R-L) > 1){
            if(L > R){
                switchL();
            }
            else{ // R > L
                switchR();
            }
        }
        if(sz(menor) + sz(mayor) + 1 == k){
            //imprimir
            ll ansL = med * sz(menor) - Lsum;
            ll ansR = Rsum - med * sz(mayor);
            cout << ansL + ansR << " ";
        }
    }
    cout << endl;
}
