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
const ll MOD = 1e9 + 7;
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
void help(ll i,ll j,ll u,ll v,ll prev,string& s,vl& ans){
// if(i>j)return;
// cout<<"debug"<<endl;
// cout<<s<<endl;
// cout<<ans<<endl;
// cout<<s[0]<<" "<<s[s.size()-1] <<endl;
if(u<v && i<j){
if(prev==0 && s[u]=='0'){
    // cout<<"debug"<<endl;
ans.pb(j);help(i,j+1,u+1,v,0,s,ans);
}
else if(prev==0 && s[u]=='1'){
    // cout<<"debug"<<endl;
    help(i+1,j+1,u+1,v,-1,s,ans);
}
else if(prev==1 && s[v]=='1'){
    // cout<<"debug"<<endl;
ans.pb(i-1);help(i,j+1,u,v-1,1,s,ans);
}
else if(prev==1 && s[v]=='0'){
    // cout<<"debug"<<endl;
    help(i+1,j+1,u,v-1,-1,s,ans);
}
else{
    // if(s.size()>2)
    help(i+1,j-1,u+1,v-1,s,ans);
}}
}
void solve() {
ll n;
cin>>n;
string s;
cin>>s;
ll c1=0,c2=0;
FOR(i,0,n){
    if(s[i]=='1')c1++;
    else c2++;
}
if(c1!=c2){cout<<-1<<endl;return;}
vl ans={};
help(1,n,0,n-1,s,ans);
// cout<<ans<<endl;
cout<<sza(ans)<<endl;
for (auto i:ans)cout<<i<<" ";cout<<endl;
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