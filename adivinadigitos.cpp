// MALISIMO ESTE CODIGO RE BUGGEADO
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
ll block = 0;
ll mask[60];
ll og[60];
bool ex[60];
int n,m;
int mod = 127;
ll vBit(int bit){return (1ll) << bit;}
vector<ll> shift(vector<ll> &prev, int s){
    vector<ll> act(mod);
    forn(i,sz(prev)){
        int p = (i + s);
        if(p >= mod){p-=mod;}
        act[p] = prev[i];
    }
    return act;
}
void setear2(int bit, bool one){
    // si one, paso de 0 -> 1
    // si !one paso de 1->0
    ll v = (1ll << bit);
    forn(i,m){
        if(one){
            mask[i] += (og[i] & v);
        }
        else{
            mask[i] -= (og[i] & v);
        }
    }
}
void setear(ll con, bool one){
    forn(i,n){
        ll v = vBit(i);
        if(con & v){
            setear2(i,one);
        }
    }
}
ll conexions(int bit){
    ll v = (1ll << bit);
    ll ans = 0;
    forn(i,m){
        if(mask[i] & v){
            ans = (ans | mask[i]); 
        }
    }
    if(ans & v){ans-=v;}
    return ans;
}
int sh1[65];
int sh2[65];
void iniciar(){
    sh1[0] = 1;
    sh2[0] = 2;
    forr(i,1,63){
        sh1[i] = (sh1[i-1] * 10) % 127;
        sh2[i] = (sh2[i-1] * 10) % 127;
    }
}
bool posible(){
    forn(i,m){
        if(mask[i] == 0){
            return false;
        }
    }
    return true;
}
void sum(vector<ll> &a, vector<ll> &b){ // meto todo en a
    forn(i,sz(a)){
        a[i]+=b[i];
    }
}
void back(int bit, vector<ll> &r){
    // si puse todos los bits // osea bit == n // sumo en 0
    if(bit == n){
        r[0]++;
        return;
    }
    if(block & vBit(bit)){
        back(bit+1,r);
        return;
    }
    
    if(!ex[bit]){    // casos especiales // 1. si no aparece // puede ser cualquiera
        back(bit+1,r);
        return;
    }  
    
    ll con = conexions(bit);
    // casos especiales
    // 1. si no aparece //YA ESTA HECHO
    // 2. si c == 0 y not blocked -> valor debe ser un 1 // YA ESTA HECHO
    // 2. si c == x y c de x == bit // si son independientes // resuelvo general y aplico shifts // HECHO
    // 3. Si  hay un conjunto donde tenga a -> !b, !c !d !e... elijo siempre un encendido
    if(con  == 0){
        back(bit+1,r);
        r = shift(r,sh1[bit]);
        return;
    }
forn(i,n){
        if(con == vBit(i)){ // bit, i son los bits independientes del resto
            ll con2 = conexions(i);
            if(con2 == vBit(bit)){ // si entra es porque hay un conjunto de 2 independientes
                vector<ll> a(mod,0);
                setear(con,false); block ^= con;
                if(posible()){back(bit+1,a);}
                else{
                    setear(con,true);   block ^= con;
                    break;      
                }
                setear(con,true);   block ^= con;
                ll shift1 = (sh1[bit] + sh2[i]) % 127;
                ll shift2 = (sh2[bit] + sh1[i]) % 127;
                setear(con,false); block ^= con;
                if(posible()){
                    r = shift(a,shift1);
                }
                setear(con,true); block ^= con;
                setear(con2,false); block ^= con2;
                if(posible()){
                    a = shift(a,shift2);
                    sum(r,a);
                }
                setear(con2,true); block ^= con2;
                return;
            }
        }
    }   
        //caso normal donde hay que splitear
        vector<ll> b(mod,0);
        vector<ll> c(mod,0);
        setear(con,false); block = block ^ con;
        if(posible()){
            back(bit+1,r);
            r = shift(r,sh1[bit]);
            forn(i,n){
                if(vBit(i) & con){
                    r = shift(r,sh2[i]);
                }
            }
        }
        setear(con,true);  block = block ^ con;
        setear2(bit,false); block = block  ^ vBit(bit);
        if(posible()){
            back(bit+1,b);
            b = shift(b,sh2[bit]);
        }
        setear2(bit,true); block = block  ^ vBit(bit);
        sum(r,b); 
}
vector<long long> adivina(vector<string> &a){
    iniciar();
    forn(i,sz(a)){reverse(all(a[i]));} // lo doy vuelta para que el bit 0 vaya adelante
    m = sz(a);
    n = sz(a[0]);
    forn(i,m){
        forn(bit,n){
            if(a[i][bit] == '1'){
                ex[bit] = true;
                ll v = (1ll << bit);
                og[i] += v;
                mask[i]+= v;
            }
        }
    }
    vector<ll> ans(127,0);
    // si hay algun full ceros -> ans = 0
    if(!posible()){return ans;}
    //
    back(0,ans);
    // shifteo por los bits que no aparecen
    forn(i,n){
        if(ex[i]){continue;}
        vector<ll> a1 = shift(ans,sh1[i]);
        vector<ll> a2 = shift(ans,sh2[i]);
        sum(a1,a2);
        ans = a1;
    }
    return ans;
}
