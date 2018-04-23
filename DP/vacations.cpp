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
	int n;
	cin >> n;
	vi a(n);
	REP(i,n)cin >> a[i]; 
	vii dp(n,vi(3));

	dp[0][0]=1;
	int m = 0;
	for(int i = 0; i<n; i++){
		if(i!=0){
			m = *min_element(dp[i-1].begin(), dp[i-1].end());
			dp[i][0] = m+1;
		}
		switch(a[i]){
			case 0:
				if(i == 0){
					dp[i][1]=1;
					dp[i][2]=1;
				}
				else{
					dp[i][1] = dp[i][2] = m + 1 ;
				}
				break;
			case 1:
				if(i==0 ){
					dp[i][1] = 1;
					dp[i][2] = 0;
				}
				else{
					if(a[i-1]==0 || a[i-1]==2){
						dp[i][1] = m+1;
						dp[i][2] = m;
					}
					else if(a[i-1]==1){
						if(dp[i-1][1]==dp[i-1][2]){
							dp[i][1]=m+1;
							dp[i][2]=m;
						}	
						else{
							dp[i][1] = m+1;
							dp[i][2] = m+1;
						}

					}
					else{
						dp[i][1] = m+1;
						if(dp[i-1][1]<=dp[i-1][2]) dp[i][2] = m;
						else dp[i][2] = m+1; 
					}
				}
				break;
			case 2:
				if(i==0){
					dp[i][1] = 0;
					dp[i][2] = 1;
				}
				else{
					if(a[i-1]==0 || a[i-1]==1){
						dp[i][1] = m;
						dp[i][2] = m+1;	
					}
					else if(a[i-1]==2){
						if(dp[i-1][1]==dp[i-1][2]){
							dp[i][1]=m;
							dp[i][2]=m+1;
						}	
						else{
							dp[i][1] = m+1;
							dp[i][2] = m+1;
						}
					}
					else{
						dp[i][2] = m+1;
						if(dp[i-1][2]<=dp[i-1][1]) dp[i][1] = m;
						else dp[i][1] = m+1;
					}
				}
				break;
			case 3:
				if(i==0){
					dp[i][1] = 0;
					dp[i][2] = 0;
				}
				else{
					if(a[i-1]==0 || dp[i-1][1]==dp[i-1][2]){
						dp[i][1] =dp[i][2]= m;
					}
					else if(a[i-1]==1){
						dp[i][1] = m;
						dp[i][2] = m+1;
						
					}
					else if(a[i-1]==2){
						dp[i][1] = m+1;
						dp[i][2] = m;
					}
					else{
						if(dp[i-1][1] < dp[i-1][2]){
							dp[i][1] = m+1;
							dp[i][2] = m;
						}
						else if(dp[i-1][1] > dp[i-1][2]){
							dp[i][2] = m+1;
							dp[i][1] = m;	
						}
					}
				}
				break;
		}
	}
	cout << *min_element(dp[n-1].begin(),dp[n-1].end()) << "\n";

	return 0;
}