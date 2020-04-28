#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////




map<string,ll> mp;//0:未定,1:,2,

int chk(string s){
    rep(i,3){
        ll t1 = 0;
        ll t2 = 0;
        rep(j,3){
            if(s[i*3+j]=='1')t1++;
            if(s[i*3+j]=='2')t2++;
        }
        if(t1==3){
            return 10;
        }else if(t2==3){
            return -1;
        }
    }
    rep(i,3){
        ll t1 = 0;
        ll t2 = 0;
        rep(j,3){
            if(s[j*3+i]=='1')t1++;
            if(s[j*3+i]=='2')t2++;
        }
        if(t1==3){
            return 10;
        }else if(t2==3){
            return -1;
        }
    }
    return 0;
}


bool ck(string ss){
    ll tmp = 0;
    rep(i,ss.size()){
        if(ss[i]=='0')tmp++;
    }
    if(tmp>0)return false;
    else return true;
}

ll calc(string s,ll now){
    if(mp[s]!=0)return mp[s];
    ll tmp = 0;
    ll t1=0,t2=0;
    if(chk(s)!=0)return chk(s);
    if(ck(s))return 0;
    ll ans = 0;
    rep(i,9){
        if(s[i]=='0'){
            string ss = s;
            if(now==1){
                ss[i] = '1';
                ans += calc(ss,2);
            }else{
                ss[i] = '2';
                ans += calc(ss,1);
            }
        }
    }
    return mp[s] = ans;
}

char ch(char _c){
    if(_c == '2')return 'x';
    if(_c == '1')return 'o';
    else return '_';
}

void prin(string _s){
    rep(i,3){
        rep(j,3)princ(ch(_s[(2-i)*3+j]));

        print("");
    }
}


int main(){
    string s;
    s.resize(9,'0');
    prin(s);
    while(1){
        cout<<"x,yを入力"<<endl;
        while(1){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            if(0<=x && x<=2 && y<=2 && y>=0 && s[x+y*3]=='0'){
                s[x+3*y] = '1';
                break;
            }else{
                cout<<"もう一度"<<endl;
            }
        }
        prin(s);
        if(chk(s)!=0)break;
        if(ck(s))break;
        ll tmp = INF;
        ll id = -1;
        rep(j,9){
            string s2;
            if(s[j]=='0'){
                s2 = s;
                s2[j] = '2';
                if(chmin(tmp,calc(s2,1)))id = j;
            }
        }
        print(tmp);
        s[id] = '2';
        if(chk(s)!=0)break;
        if(ck(s))break;
        prin(s);
    }
    return 0;
}