#include <bits/stdc++.h>
#include<sstream> 
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ', ' << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ', '; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << '(' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define FOR(i,a,b) for( long long int i = a; i<b;i++)
#define pb push_back
int modmul(int a,int b,int m){ a %= m;b %= m; return (a * b) % m;}
int modadd(int a,int b,int m){ a %= m;b %= m; return (a + b) % m;}
int modsub(int a,int b,int m){ a %= m;b %= m; return (a - b + m) % m;}
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}
int expo(int a,int n,int md){ int res=1; while(n){ if(n&1) {res = modmul(res,a,md);--n;} else {a = modmul(a,a,md);n >>= 1;}} return res;}
int expo(int a,int n){ int res=1; while(n){ if(n&1) {res *= a;--n;} else {a *= a;n >>= 1;}} return res;}
template <typename T> bool revsort(T a, T b){return a > b;}
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e20;
const ld EPS = 1e-20;
ll maxm(ll n,vector<ll> v){
sort(all(v));
return v[n-1];
}
ll minm(ll n,vector<ll> v){
sort(all(v));
return v[0];
}
void solve() {
string s;
cin>>s;
ll n=s.size();
map<char,ll> cnt;ll ans=0; char maxo='A';map<char,ll> val;val['A']=1;val['B']=10;val['C']=100;val['D']=1000;val['E']=10000;
ll curr[n];ll maxl[n];ll sign[n];
vector<char> chars={'A','B','C','D','E'};
for (ll i = n-1; i>=0; i--)
{if(s[i]>=maxo){maxo=s[i];ans+=val[s[i]];sign[i]=1;}
else {ans-=val[s[i]];sign[i]=-1;}
cnt[s[i]]++;
curr[i]=ans;maxl[i]=maxo;
}
for (ll i = n-1;i>=0;i--)
{
   cnt[s[i]]--;
// cout<<temp<<endl;
    for(char j:chars){
        ll temp=curr[i];ll var=curr[0]-curr[i];
            if(i<=n-2){if(s[i]>=maxl[i+1])temp-=val[s[i]];else temp+=val[s[i]];}
            else{temp-=val[s[i]];}
            if(i<=n-2){if(j>=maxl[i+1])temp+=val[j];else temp-=val[j];}
            else{temp+=val[j];}
        for(char k:chars){
            if(i>=1){
                if(k<maxl[i-1])temp-=cnt[k]*val[k];
                else{

                }
            }
            // if(k<j){temp-=cnt[k]*val[k];} else temp+=cnt[k]*val[k];
        }
        cout<<i<<" "<<j<<" "<<curr[i]<<" "<<temp<<endl;
        ans=maxm(2,{ans,temp});
    }
}
cout<<ans<<endl;
}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int n = 1;
cin >> n;
for (int t = 1; t <= n; t++) {
// cout << 'Case #' << t << ': ';
solve();
}
}