#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<ll>
#define vii vector<vector<ll> >
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
	int n,m;
	cin >> n >> m;
	int d[m];
	REP(i,m)cin >> d[i];
	sort(d,d+m);

	if(d[0]== 1 || d[m-1] == n){
		cout << "NO\n";
		return 0;
	}	
	int c=1;
	REP(i,m-1){
		if(d[i+1]-d[i] == 1)c++;
		else c= 1;
		if(c>=3){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}