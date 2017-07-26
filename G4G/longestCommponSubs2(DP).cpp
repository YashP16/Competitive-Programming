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


int LCS(string a,string b){
	int n = a.length();
	int m = b.length();

	int max = 0;
	pair <int,int> coord;
	vii table(n+1,vi (m+1));
	REP(i,n+1){
		REP(j,m+1){
			if(i==0||j==0)table[i][j]=0;
			else if(a[i-1]==b[j-1]){
				table[i][j]=table[i-1][j-1]+1;
				if(table[i][j]>max){
					max = table[i][j];
					coord.F = i;
					coord.S = j;
				}
			}
			else table[i][j]=0;
		}
	}
	return max;
}


int main(){
	fast_io;
	cin.tie(NULL);
	int t,m,n;
	string a,b;
	cin >> t;
	while(t--){
		cin >> m >> n;
		cin >> a >> b;
		
		cout << LCS(a,b) << "\n";
	}
	return 0;
}