#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i < (b); i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (b-1); i >= (a); i--)
#define dforn(i,n) dforr(i,0,n)
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz(i) i.size()
using namespace std;
vector<deque<int>> tags_de;
vector<int> tag;
vector<int> sig;
string s;
string srt;
int main(){
    tags_de.resize(256,{});
    cin >> s;
    srt = s;
    sort(all(srt));
    int n = sz(s);
    if(srt[n-1] == '#'){
        srt.pop_back();
        srt = '#' + srt;
    }
    tag.resize(n);
    sig.resize(n);
    forn(i,n){
        tag[i] = i;
        char c = srt[i];
        tags_de[c].push_back(i);
    }
    forn(i,n){
        char act = s[i];
        int tag_act = tags_de[act][0];
        tags_de[act].pop_front();
        sig[tag_act] = i;
    }
    string r;
    int t = 0;
    forn(i,n){
        r.push_back(srt[t]);
        t = sig[t];
    }
    r = r.substr(1,n-1);
    cout << r << endl;
}
