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
	int n,x;
	cin >> n;
	vi a(5,0);

	REP(i,n){
		cin >> x;
		a[x]++;
	}
	int c = a[4];
	if(a[3]>=a[1]){
		c+= a[3]+(a[2]/2)+(a[2]%2);
	} 
	else{
		c+= a[3]+a[2]/2;
		a[2] = a[2]%2;
		a[1] = a[1]-a[3];
		if(a[2]==1){
			c++;
			a[1]-= 2;

		}
		if(a[1]>0){
			c+= a[1]/4;
			if(a[1]%4 != 0){
				c++;
			}
		}
	}
	cout << c << "\n";
	return 0;
}