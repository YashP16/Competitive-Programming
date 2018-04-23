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
		int n,d;
		cin >> n >> d;
		vi a(n);
		ll s =0;
		
		REP(i,n){
			cin >> a[i];
			s+= a[i];
		}
		
		bool flag =1;
		ll count = 0;
		
		if(s%n == 0){
			ll av = s/n; 
			ll extra = 0;
			FOR(i,0,d,1){
				extra = 0;
				FOR(j,i,n,d){
					count+= abs(extra);
					if(a[j]<av){
						extra += a[j]-av;
					}
					else{
						extra += a[j]-av;
					}
				}
				if(extra > 0){
					flag =0;
					break;
				}
			}
		}
		else flag =0;

		if(flag)cout << count  << "\n";
		else cout << -1 << "\n";
	}

	return 0;
}