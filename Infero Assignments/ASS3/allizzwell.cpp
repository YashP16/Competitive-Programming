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

string s = "ALLIZZWELL";
int dx[] = {-1,0,1,0,1,-1,1,-1};
int dy[] = {0,1,0,-1,1,-1,-1,1};
queue <pair <int,int> > q;
void func(int n,int m, vector <vector <char> > &mat){
	while(!q.empty()){
		queue <pair <pair<int,int>,int> > temp;

		temp.push({q.front(),1});q.pop();
		while(!temp.empty()){
			pair < pair <int,int>, int> u = temp.front(); temp.pop();
			for(int i = 0; i < 8; i++){
				pair<int,int> v = {u.F.F+dy[i],u.F.S+dx[i]};
				if(v.F >= n or v.F < 0 or v.S >= m or v.S  < 0 or mat[v.F][v.S]!= s[u.S])
					continue;
				else{
				temp.push({v,u.S+1});
				}
			}
			if(u.S+1 >s.length()){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}
int main(){
	fast_io;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector <vector <char> > mat(n,vector <char>(m));
		REP(i,n){
			REP(j,m){
				cin >> mat[i][j];
				if(mat[i][j] == 'A'){
					q.push({i,j});
				}
			}
		}
		if(n*m >= s.length())func(n,m,mat);
		else cout << "NO\n";
	}
	return 0;
}