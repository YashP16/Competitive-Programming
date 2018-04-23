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

bool canMove(vii &freq,int a,int b){
	int sum = 0;
	REP(i,10){
		sum += min(freq[a][i],freq[b][i]);
	}
	if(sum == 17)return true;
	return false;
}

int numSteps(int n,vii &graph,int s,int e){
	if(s==e) return 0; 
	queue <pair<int,int> > q;
	q.push({s,0});
	vb vis(n,0);
	vis[s] =1;
	while(!q.empty()){
		pair<int,int> f = q.front();q.pop();
		FOR(i,0,graph[f.F].size(),1){
			if(!vis[graph[f.F][i]]){
				if(graph[f.F][i] == e) return f.S+1;
				q.push({graph[f.F][i],f.S+1});
				vis[graph[f.F][i]]=1;
			}
		}
	}
	return -1;
}

int main(){
	fast_io;
	int t;
	cin >> t;
	while(t--){
		int n,s,e;
		cin >> n >> s >> e;
		vector <string> a(n);
		vii freq(n,vi(10,0));
		REP(i,n){
			cin >> a[i];
			REP(j,20){
				freq[i][int(a[i][j])-int('0')]++;
			}
		}
		vii graph(n);
		REP(i,n-1){
			FOR(j,i+1,n,1){
				if(canMove(freq,i,j)){
					graph[i].PB(j);
					graph[j].PB(i);
				}
			}
		}
		cout << numSteps(n,graph,s-1,e-1) << "\n";
	}
	return 0;
}