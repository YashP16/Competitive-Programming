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

const int N = 1010;

int mat[N][N];
vector<vector<int> > dist(N,vector<int>(N,MAX));

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;
queue<pair<int,int> > q;

void func(){
	while(!q.empty()){
		pair<int,int> u = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			pair<int,int> v = {u.first+dy[i],u.second+dx[i]};

			if(v.first >= n or v.first < 0 or v.second >= m or v.second < 0 or mat[v.first][v.second]!=1)
				continue;
			else if(dist[v.first][v.second] != MAX and dist[v.first][v.second] > dist[u.first][u.second]+1){
				dist[v.first][v.second] = dist[u.first][u.second]+1;
			}
			else if(dist[v.first][v.second] == MAX){
				dist[v.first][v.second] = dist[u.first][u.second]+1;
				mat[v.first][v.second] = 2;
				q.push(v);
			}
		}
	}
}

int main(){
	// fast_io;
	cin >> n >> m;
	REP(i,n){
		REP(j,m){
			cin >>  mat[i][j];
			if(mat[i][j] == 2){
				q.push({i,j});
				dist[i][j] = 0;
			}
		}
	}
	func();
	int maxi = 0;
	REP(i,n){
		REP(j,m){
			if(mat[i][j] == 1){
				cout << -1 << endl;
				return 0;
			}
			maxi = max(maxi, dist[i][j]);
		}
	}
	cout << maxi << endl;
	return 0;
}