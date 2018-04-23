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
#define vI vector<ll>
#define vII vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;


int main(){
	fast_io;
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vi minSal(n);
		REP(i,n)cin >> minSal[i];
		vi offSal(m), maxJobOff(m),jobOff(m,0);
		REP(i,m) cin >> offSal[i] >> maxJobOff[i];
		vector <string> qual(n);
		REP(i,n)cin >> qual[i];
		
		int noJob = 0;
		int mSal=0;
		ll totalSal=0;
		REP(i,n){
			int comp =-1;
			mSal = minSal[i];
			REP(j,m){
				if(qual[i][j] == '1'){
					if(offSal[j]>mSal && maxJobOff[j] > jobOff[j]){
						mSal = offSal[j];
						comp = j;
					}
				}				
			}
			if(comp == -1)noJob++;
			else{
				jobOff[comp]++;
				totalSal+= offSal[comp]; 
			}
		}
		int x = 0;
		REP(i,m)if(jobOff[i] == 0)x++;
		cout << n-noJob << " " << totalSal << " " << x << "\n";

	}

	return 0;
}