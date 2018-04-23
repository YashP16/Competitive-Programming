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

class Compare
{
public:
    bool operator() (const pair<int, pair<int,int> > &a,const pair<int, pair<int,int> > &b){
		if(a.F >b.first)return true;
		return false;
    }
};


int dist(int n,int m,vbb &check,vii &mat,int x,int y){
	vii weight(n,vi(m,MAX));
	priority_queue < pair<int, pair<int,int> >, vector < pair <int,pair <int,int> > > , Compare > Q;
	Q.push(MP(mat[0][0],MP(0,0)));
	weight[0][0]=mat[0][0];
	int count = 0;
	while(!Q.empty()){
		pair<int,pair<int,int> > f = Q.top();
		if(!check[f.S.F][f.S.S]){
			if(f.S.F-1>=0){
				if(weight[f.S.F-1][f.S.S]>f.F+mat[f.S.F-1][f.S.S] && !check[f.S.F-1][f.S.S]){
					Q.push(MP(f.F+mat[f.S.F-1][f.S.S],MP(f.S.F-1,f.S.S)));
					weight[f.S.F-1][f.S.S]=f.F+mat[f.S.F-1][f.S.S];
				}
			}
			if(f.S.F+1<n){				
				if(weight[f.S.F+1][f.S.S]>f.F+mat[f.S.F+1][f.S.S]&& !check[f.S.F+1][f.S.S]){
					Q.push(MP(f.F+mat[f.S.F+1][f.S.S],MP(f.S.F+1,f.S.S)));
					weight[f.S.F+1][f.S.S] =f.F+mat[f.S.F+1][f.S.S];
				}
			}
			if(f.S.S+1<m){
				if(weight[f.S.F][f.S.S+1]>f.F+mat[f.S.F][f.S.S+1]&& !check[f.S.F][f.S.S+1]){
					Q.push(MP(f.F+mat[f.S.F][f.S.S+1],MP(f.S.F,f.S.S+1)));
					weight[f.S.F][f.S.S+1]=f.F+mat[f.S.F][f.S.S+1];
				}
			}
			if(f.S.S-1>=0){
				if(weight[f.S.F][f.S.S-1]>f.F+mat[f.S.F][f.S.S-1] && !check[f.S.F][f.S.S-1] ){
					Q.push(MP(f.F+mat[f.S.F][f.S.S-1],MP(f.S.F,f.S.S-1)));
					weight[f.S.F][f.S.S-1]=f.F+mat[f.S.F][f.S.S-1];
				}
			}
		}
		check[f.S.F][f.S.S] = 1;
		if(f.S.F == x && f.S.S == y) break;
		Q.pop();
	}
	return weight[x][y];  
}

int main(){
	fast_io;
	int t;
	cin >> t; 
	while(t--){
		int n,m;
		cin >> n >> m;
		vii mat(n,vi(m));
		REP(i,n)REP(j,m) cin >> mat[i][j];
		int x,y,t;
		cin >> x >> y >> t;
		vbb check(n,vb(m,0));
		int t1 = dist(n,m,check,mat,x-1,y-1);
		if(t1<t)cout << "YES\n" << t-t1 << "\n";
		else cout << "NO\n";  
	}	
	return 0;
}