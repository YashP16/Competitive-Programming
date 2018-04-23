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
	int n,m;
	cin >> n >> m;
	vi cat(n+1,0);
	REP(i,n)cin >> cat[i+1];
	vii tree(n+1);
	int x,y;
	REP(i,n-1){
		cin >> x >> y;
		tree[x].PB(y);
		tree[y].PB(x);
	}
	vb isleaf(n+1);
	for(int i = 1;i<=n;i++){
		if(tree[i].size()==1)isleaf[i]=1;
	}
	int count = 0;
	stack <pair<int,int> > s;
	s.push(make_pair(1,cat[1]));

	int t = s.top().F;
	int c = s.top().S;
	vb visited(n+1,0);
	visited[1]=1;
	while (!s.empty()){
		if(!tree[t].empty()){
			if(!visited[tree[t][0]]){
				if(cat[tree[t][0]]==1 )s.push(make_pair(tree[t][0],c+1));
				else s.push(make_pair(tree[t][0],0));
				visited[tree[t][0]]=1;
			}
			tree[t].erase(tree[t].begin());
		}
		else s.pop();
		if(!s.empty()){
			t = s.top().F;
			c = s.top().S;
		}
		if(c<=m && isleaf[t] && t!=1){
			count++;
			s.pop();
			if(!s.empty()){
				t = s.top().F;
				c = s.top().S;
			}
		}
		else if(c>m){
			s.pop();
			if(!s.empty()){
				t = s.top().F;
				c = s.top().S;
			}
		}
	}
	cout << count << "\n";

	return 0;
}