#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(int  i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<int>
#define vii vector<vector<int> >
#define vbb vector < vector <bool> >
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
	int n,m,l;
	cin>> n >> m >> l;
	vii island (n,vi (m));
	vbb check (n,vector<bool> (m,0));
	REP(i,n){
		REP(j,m)cin >> island[i][j];
	}
	vi set;
	int count = 0;
	REP(i,n){
		REP(j,m){
			if(island[i][j]==1 && check[i][j]== 0){
				count = 0;
				stack <pair <int,int> > s;
				s.push(make_pair(i,j));
				count++;
				while (!s.empty()){
					pair <int,int> top;
					top = s.top();
					check[top.F][top.S] = 1;
					if(top.F>0 && (island[top.F-1][top.S] == 1 && check[top.F-1][top.S] == 0)){
						s.push(make_pair(top.F-1,top.S)); 
						check[top.F-1][top.S] = 1;
						count++;
					}
					else if(top.S>0 && (island[top.F][top.S-1] == 1 && check[top.F][top.S-1] == 0)){
						s.push(make_pair(top.F,top.S-1)); 
						check[top.F][top.S-1] = 1;
						count++;
					}
					else if(top.F<n-1 && (island[top.F+1][top.S] == 1 && check[top.F+1][top.S] == 0)){
						s.push(make_pair(top.F+1,top.S)); 
						check[top.F+1][top.S] = 1;
						count++;
					}
					else if(top.S<n-1 && (island[top.F][top.S+1] == 1 && check[top.F][top.S+1] == 0)){
						s.push(make_pair(top.F,top.S+1)); 
						check[top.F][top.S+1] = 1;
						count++;
					}
					else{
						s.pop();
					}
				}
				set.PB(count);
			}
		}
	}
	sort(set.begin(), set.end());
	int res = 0;
	int c = min(l,(int)set.size());
	REP(i,c)res+= set[set.size()-1-i];
	cout << res << " " << set.size() ;
	return 0;
}