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
	ll n,m,k;
	cin >> n >> m >> k;
	vector < vector<pair<ll,ll> > > graph(n+1);
	ll x,y,w;
	REP(i,m){
		cin >> x >> y >> w;
		graph[x].PB({y,w});
		graph[y].PB({x,w});
	}	

	vb f(n+1,0);
	REP(i,k){
		cin >> x;
		f[x]=1;
	}
	ll mi = -1;
	FOR(i,1,n+1,1){
		if(f[i]){
			FOR(j,0,graph[i].size(),1){
				if(!f[graph[i][j].F]){
					if(mi == -1) mi = graph[i][j].S;
					else mi = min(mi,graph[i][j].S);
				}
			}
		}
	}
	cout << mi << "\n";
	return 0;
}