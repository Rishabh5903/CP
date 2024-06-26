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
void dfs(ll i,ll j,vector<vector<ll>>& v,ll& temp){
    if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]==0)return;
    temp+=v[i][j];
    v[i][j]=0;
    dfs(i+1,j,v,temp);dfs(i,j+1,v,temp);dfs(i-1,j,v,temp);dfs(i,j-1,v,temp);
    return;
    
}
void solve() {
ll n,m;ll ans=0;
cin>>n>>m;
ll l[n];
vector<vector<ll>> v(n,vector<ll>(m));
for(ll i=0;i< n;i++){
    FOR(j,0,m){
        cin>>v[i][j];
    }
}
FOR(i,0,n){
    FOR(j,0,m){
        ll temp=0;
        if(v[i][j]>0)dfs(i,j,v,temp);
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