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


ll solve(ll i,vI &dp,int m,vI &a){
	if(i>=m) return 0;
	if(dp[i]!= -1)return dp[i];
	else{
		// cout << "a[i]*i= "<< a[i]*i << "\n";
		dp[i] = max((a[i]*i)+solve(i+2,dp,m,a),solve(i+1,dp,m,a));
		
		// cout << dp[i]<<"\n";
		return dp[i];
	}
}

int main(){
	fast_io;
	vI a(100001,0);
	int n;
	cin >> n;
	int x;
	int m = 0;
	REP(i,n){
		cin >> x;
		a[x]++;
		if(x>m)m = x;
	}
	vI dp(m+1,-1);
	cout << solve(1,dp,m+1,a) << "\n";


	return 0;
}