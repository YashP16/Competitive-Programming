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

vi get_dist(int n, vector < vector< pair <int,int> > > &graph, int x){
	int dist[n+1];
	vb vis(n+1,0);
	queue <int> Q;
	Q.push(x);
	vis[x]=1;
	dist[x]=0;
	while(!Q.empty()){
		int f = Q.front(); 
		FOR(i,0,graph[f].size(),1){
			if(!vis[graph[f][i].F]){
				Q.push(graph[f][i].F);
				vis[graph[f][i].F]=1;
				dist[graph[f][i].F]=dist[f]+graph[f][i].S;
			}
		}
		Q.pop();
	}
	vi result(2);
	result[0]= max_element(dist+1, dist+n+1)-dist;
	result[1]=dist[result[0]];
	return result;
}

int main(){
	fast_io;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector < vector< pair <int,int> > > graph(n+1);
		int a,b,w;
		REP(i,n-1){
			cin >> a >> b >> w;
			graph[a].PB(MP(b,w));
			graph[b].PB(MP(a,w)); 
		}
		vi s = get_dist(n,graph,1);
		vi result = get_dist(n,graph,s[0]);
		int d = result[1];
		int money = 0;
		if(d>100)money = 100;
		if(d >1000) money = 1000;
		if(d > 10000) money = 10000;
		cout << money << " " << d << "\n";

	}	
	return 0;
}