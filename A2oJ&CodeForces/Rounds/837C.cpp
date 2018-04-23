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
	int n,a,b;
	cin >>n>> a >> b; 
	int A = a*b;
	vector <pair < pair<int,int>,int> > v(n);
	REP(i,n){
		cin >> v[i].F.F >> v[i].F.S;
		v[i].S = v[i].F.F * v[i].F.S;
	}
	int max = 0;
	REP(i,n-1){
		FOR(j,i+1,n,1){
			if(v[i].S+v[j].S <= A && v[i].S+v[j].S > max ){
				if(a - v[i].F.F >= v[j].F.F || a - v[i].F.S >= v[j].F.F){				// horizontal-verticle , horizontal
					if(v[j].F.S <= b )max = v[i].S+v[j].S;
					
				}
				if(a - v[i].F.F >= v[j].F.S || a - v[i].F.S >= v[j].F.S){			// horizontal-verticle , vertical
					if(v[j].F.F <= b){
						max = v[i].S+v[j].S;
					}
				}
				if(b-v[i].F.S >= v[j].F.S || b - v[i].F.F >= v[j].F.S ){				// horizontal-verticle , horizontal
					if(v[j].F.F <= a){
						max = v[i].S+v[j].S;
					}
				}
				if(b-v[i].F.S >= v[j].F.F || b - v[i].F.F >= v[j].F.F ){
					if(v[j].F.S <= a){
						max = v[i].S+v[j].S;
					}
				}
			}
		}
	}

	cout << max << "\n";
	return 0;
}