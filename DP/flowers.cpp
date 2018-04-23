#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<int>
#define vii vector<vector<int> >
#define vb vector<bool>
#define vbb vector<vector<bool> >
#define vI vector<ll>
#define vII vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;


int main(){
	fast_io;
	ll mod = 1e9 +7;
	ll t,k;
	cin >> t >> k;
	vII f(t,vI(2));
	ll m = 0;
	REP(i,t){
		cin >> f[i][0] >> f[i][1];
		m = max(m,f[i][1]);
	}
	
	vI dp(m+1,-1);
	vI ps(m+1,0);
	dp[0] = 1;
	FOR(i,1,k,1) dp[i]=1;
	if(k==1)dp[1]=2;
	ps[1] = dp[1];	
	FOR(i,2,m+1,1){
		if(dp[i]==-1){
			dp[i]= (dp[i-1]+dp[i-k])%mod;
		}
		ps[i]= (ps[i-1] + dp[i]);
	}
	REP(i,t) cout << (ps[f[i][1]] - ps[f[i][0]-1])%mod << "\n";
	
	return 0;
}