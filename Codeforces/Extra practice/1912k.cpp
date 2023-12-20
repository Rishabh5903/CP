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
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define FOR(i,a,b) for( long long int i = a; i<b;i++)
#define pb push_back
#define ce(x) cout<<x<<endl
int modmul(int a,int b,int m){ a %= m;b %= m; return (a * b) % m;}
int modadd(int a,int b,int m){ a %= m;b %= m; return (a + b) % m;}
int modsub(int a,int b,int m){ a %= m;b %= m; return (a - b + m) % m;}
int gcd(int a, int b){ if(b == 0) return a; return gcd(b, a % b);}
int expo(int a,int n,int md){ int res=1; while(n){ if(n&1) {res = modmul(res,a,md);--n;} else {a = modmul(a,a,md);n >>= 1;}} return res;}
int expo(int a,int n){ int res=1; while(n){ if(n&1) {res *= a;--n;} else {a *= a;n >>= 1;}} return res;}
template <typename T> bool revsort(T a, T b){return a > b;}
const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e20;
const ld EPS = 1e-20;
ll maxm(vector<ll> v){
sort(all(v));
return v[v.size()-1];
}
ll minm(vector<ll> v){
sort(all(v));
return v[0];
}
void solve() {
ll n;
cin>>n;
ll l[n];
for(ll i=0;i< n;i++){
cin>>l[i];
}
vector<vvl> v(n,vvl(2,vl(2)));
v[1][l[1]%2][l[0]%2]=1;ll ans=0;
    if(l[2]%2){
        v[2][1][0]+=(v[2-1][0][1])%MOD;
        v[2][1][0]%=MOD;
        v[2][1][1]+=(v[2-1][1][0])%MOD;
        v[2][1][1]%=MOD;
    }
    else{
        v[2][0][0]+=(v[2-1][0][0])%MOD;
        v[2][0][0]%=MOD;
        v[2][0][1]+=(v[2-1][1][1])%MOD;
        v[2][0][1]%=MOD;
    }
ans=(ans+v[2][0][0])%MOD;
ans=(ans+v[2][0][1])%MOD;
ans=(ans+v[2][1][0])%MOD;
ans=(ans+v[2][1][1])%MOD;
FOR(i,3,n){
    if(l[i]%2){
        v[i][1][0]+=(3*v[i-1][0][1])%MOD;
        v[i][1][0]%=MOD;
        v[i][1][1]+=(3*v[i-1][1][0])%MOD;
        v[i][1][1]%=MOD;
    }
    else{
        v[i][0][0]+=(3*v[i-1][0][0])%MOD;
        v[i][0][0]%=MOD;
        v[i][0][1]+=(3*v[i-1][1][1])%MOD;
        v[i][0][1]%=MOD;
    }
ans=(ans+v[i][0][0])%MOD;
ans=(ans+v[i][0][1])%MOD;
ans=(ans+v[i][1][0])%MOD;
ans=(ans+v[i][1][1])%MOD;
}
cout<<ans<<endl;
}
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int n = 1;
// cin >> n;(3*
for (int t = 1; t <= n; t++) {
// cout << 'Case #' << t << ': ';
solve();
}
}