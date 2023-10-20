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
    int dp[1000][1000];
    bool chk(int i,int j,vector<string>& words,vector<int>& groups){
        int n=words[i].size();
        if(words[j].size()!=n || groups[i]==groups[j])return 0;
        int cnt=0;
        for (int k=0;k<n;k++){
            if(cnt>=2)break;
            if(words[i][k]!=words[j][k])cnt++;
        }
        if(cnt==1)return 1;
        else return 0;
            
    }
    int solve(int i,int j,int prev,vector<string>& words, vector<int>& groups){
        if(dp[i][j]!=-1)return dp[i][j];
        if(j==words.size())return dp[i][j]=1;
        if(chk(prev,j,words,groups)){
            // prev=j;
            return dp[i][j]=max(1+solve(j,j+1,j,words,groups),solve(i,j+1,prev,words,groups));
        }
        else return dp[i][j]=solve(i,j+1,prev,words,groups);
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        for(int i=0;i<1000;i++){
                    for(int j=0;j<1000;j++){
            dp[i][j]=-1;
        }
        }
        for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
            solve(i,j,i,words,groups);
        }
        }
        
    vector<string>ans={};
        for(int i=0;i<n;i++){
            vector<string>temp={words[i]};int prev=i;
            for(int j=i+1;j<n;j++){
                if( chk(prev,j,words,groups) && (dp[prev][j]==1+dp[j][j+1] || (i==n-2 && j==n-1))){
                    temp.push_back(words[j]);prev=j;
                }
            }
            if(temp.size()>ans.size())ans=temp;
        }
        return ans;
    }

void solve() {int n;
vector<string> words;
vector<int> groups;
// n=11;
// words={"dba","dac","ac","ccc","dc","cdc","ab","ad","dcc","cc","ba"};
// groups={1,8,11,6,3,5,10,8,7,6,7};
n=9;
words={"bad","dc","bc","ccd","dd","da","cad","dba","aba"};
groups={9,7,1,2,6,8,3,7,2};
// cout<<dp[1][2]<<" "<<dp[2][3]<<endl;
getWordsInLongestSubsequence(n,words,groups);
cout<<dp[2][4]<<" "<<dp[4][6]<<endl;
cout<<getWordsInLongestSubsequence(n,words,groups)<<endl;
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