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
	int n;
	cin >> n;
	vector <pair <int,pair<int,int> > > pts(n); 
	pts[0].F = 0;
	vi curr_color(n,0);
	REP(i,n-1)cin >> pts[i+1].F;
	REP(i,n){
		cin >> pts[i].S.S;
		pts[i].S.F = i+1;
	}
	sort all(pts);
	int count = 0;
	
	REP(i,n){
		if(pts[i].S.S!=curr_color[i]){
			count++;
			curr_color[i]=pts[i].S.S;
			FOR(j,0,n,1){
				if(pts[j].F == pts[i].S.F){
					curr_color[j] = pts[i].S.S;
				}
			}
		}
	}
	cout << count << "\n";
	return 0;
}