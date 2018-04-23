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
	int n;
	cin >> n;
	int x,y;
	vii g(n+1);
	
	vector <bool> vis(n+1,0);
	vi u(n+1,-1);
	vector <double> prob(n+1,-1);
	vi dist(n+1,0);

	REP(i,n-1){
		cin >> x >> y;
		g[x].PB(y);
		g[y].PB(x);
	}
	stack <int> s;
	s.push(1);
	vis[1] = 1;
	double total = 0;
	int prev;
	while(!s.empty()){
		int t = s.top();
		if(u[t] == -1){
			u[t] = 0;
			REP(l,g[t].size()){
				if(!vis[g[t][l]])u[t]++;
			}
		}
		if(prob[t] == -1 && t == 1) prob[t] = 1.00;
		else if(t>1&& prob[t]==-1)prob[t] = prob[prev]/(double)u[prev];
		
		if(g[t].empty()){
			s.pop();
		}
		
		else{
			int m = g[t][0];
			if(!vis[m]){
				dist[m] = dist[t]+1; 
				s.push(m);
				vis[m] = 1;
				prev = t;
			}
			g[t].erase(g[t].begin());
		}
	}

	FOR(i,1,n+1,1){
		if(u[i]==0){
			total += (double)dist[i]*prob[i];
		}
	}
	
	printf( "%.15f\n",total);

	return 0;
}