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
	int n,m ;
	cin >> n >> m;
	vector <bool> c(n+1,0);
	
	FOR(i,1,n+1,1){
		bool x;
		cin >>x;
		c[i] = x;
	}

	vi u(n+1,-1);
	vii g(n+1);
	vector <bool> reached(n+1,0);
	
	REP(i,n-1){
		int x,y;
		cin >> x >> y;
		g[x].PB(y);
		g[y].PB(x);
	}

	vector <bool> vis(n+1,0);
	int count =0;
	int l =0;
	
	stack <pair <int,int> > s;
	s.push(make_pair(1,0));
	vis[1]=1;
	
	if(c[1])s.top().S = 1;
	
	while(!s.empty()){
		int t = s.top().F;
		
		if(u[t] == -1){
			u[t] = 0;
			REP(l,g[t].size()){
				if(!vis[g[t][l]])u[t]++;
			}
		}

		l = s.top().S; 
		
		if(g[t].empty()){
			s.pop();
		}
		
		else{
			int v = g[t][0];
			
			if(c[v])l++;
			else l = 0;
			
			if(l<=m){
				if(u[v]==0 && !reached[v]){
					count++;
					reached[v]=1;
				}
				else if(!vis[v]){
					s.push(make_pair(v,l));
					vis[v] = 1;
				}
			}	
			g[t].erase(g[t].begin());
			
		}
	}
	
	cout << count <<"\n";

	return 0;
}