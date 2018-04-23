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


int solve(int n,vii & dp,int k,int d,int x){
	int m = 1e9 + 7;
	int r = min(k,n);
	if(x==0 && n<d)return dp[x][n] = 0;
	if(dp[x][n]!= -1)return dp[x][n];

	dp[x][n] = 0;
	for (int i =0 ; i<= r;i++){
		if(i<d)dp[x][n] = dp[x][n]%m + solve(n-i,dp,k,d,x)%m;
		else dp[x][n] = dp[x][n]%m + solve(n-i,dp,k,d,1)%m;
	}

	return dp[x][n]%m;
}

int main(){
	fast_io;
	int n,k,d;
	cin >> n >> k >> d;
	vii dp(2,vi(n+1,-1));
	dp[1][0] = dp[1][1] = 1;
	cout << solve(n,dp,k,d,0) << "\n";	
	
	return 0;
}