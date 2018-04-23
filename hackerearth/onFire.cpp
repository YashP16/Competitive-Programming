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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
using namespace std;

int func(int n,int m,vii &planet,int x,int y,int count){
	int t = 0;
	if(planet[x][y]==1){
		queue <pair <int,int> > Q;
		Q.push(make_pair(x,y));
		t++;
		planet[x][y] = 0;
		while(!Q.empty()){
			pair <int,int> f = Q.front();
			if(f.F-1>=0){
				if(planet[f.F-1][f.S] == 1){
					Q.push(make_pair(f.F-1,f.S));
					planet[f.F-1][f.S] = 0;
					t++;
				}
			}
			if(f.F+1<n){				
				if(planet[f.F+1][f.S] == 1){
					Q.push(make_pair(f.F+1,f.S));
					planet[f.F+1][f.S] = 0;
					t++;
				}
			}
			if(f.S+1<m){
				if(planet[f.F][f.S+1] == 1){
					Q.push(make_pair(f.F,f.S+1));
					planet[f.F][f.S+1] = 0;
					t++;
				}
			}
			if(f.S-1>=0){
				if(planet[f.F][f.S-1] == 1){
					Q.push(make_pair(f.F,f.S-1));
					planet[f.F][f.S-1] = 0;
					t++;
				}
			}
			Q.pop();
		}
	}
	return count-t;
}


int main(){
	fast_io;
	int n,m,q;
	cin >> n >> m >> q;
	vii planet(n,vi(m));
	int count= 0;
	REP(i,n){
		REP(j,m){
			cin >> planet[i][j];
			if (planet[i][j] == 1) count++;
		}
	}
	int x,y;
	while(q--){
		cin >> x >> y;
		count = func(n,m,planet,x-1,y-1,count);
		cout << count << "\n";
	}
	return 0;
}