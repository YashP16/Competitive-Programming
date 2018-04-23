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
#define sz size()
#define InF  2147483647
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;

void dfs(vii &g,vb &c,vb &vis,vi &u,int &count,int t,int l,int m){
	if(u[t] == -1){
		u[t] = 0;
		REP(l,g[t].size()){
			if(!vis[g[t][l]])u[t]++;
		}
	}
	while(!g[t].empty()){
		int v = g[t][0];
		if(c[v])l++;
		else l = 0;
		
		if(l<=m){
			if(u[v]==0 && !vis[v]){
				count++;
				vis[v]=1;
			}
			else if(!vis[v]){
				vis[v] = 1;
				dfs(g,c,vis,u,count,v,l,m);
			}
		}	
		g[t].erase(g[t].begin());
	}
	return;
}


int main(){
	fast_io;
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	
	vb c(n+1);
	bool d;	
	FOR(i,1,n+1,1){
		cin >>d;
		c[i] = d;
	}

	vii g(n+1);
	int x,y;
	REP(i,n-1){
		cin >> x >> y;
		g[x].PB(y);
		g[y].PB(x);
	}

	vi u(n+1,-1);
	int count = 0;
	vb vis(n+1,0);
	int l = 0;
	if(c[1])l++;
	dfs(g,c,vis,u,count,1,l,m);
	cout << count << "\n";
	
	return 0;
}