#include <bits/stdc++.h>

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define all(v) ((v).begin(),(v).end())
#define vi vector<ll>
#define vii vector<vector<ll> >
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
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector < vector<int> > v(n+1);
		vector < int > degree(n+1);
		vector < vector<int> > data(n);
		int x,y;
		while(m--){
			cin >> x >> y;
			v[x].PB(y);
			v[y].PB(x);
			degree[x]++;
			degree[y]++;
		}
		bool flag = 0;
		FOR(i,0,n,1){
			if(flag!=1){
				set <int> rem;
				vector<int> deg(degree);
				FOR(j,1,n+1,1){
					if(degree[j]<=i)data[i].PB(j);
				}
				if(data[i].size()!=0){
					FOR(k,0,data[i].size(),1){
						rem.insert(data[i][k]);
						FOR(x,0,v[data[i][k]].size(),1){
							deg[v[data[i][k]][x]]--;
							if(deg[v[data[i][k]][x]] == 0 )rem.insert(v[data[i][k]][x]);
						}
					}
					if(rem.size()==n){
					 	cout << n-1 << " ";
						flag =1;
					}
					else cout << rem.size() << " ";
				}
				else cout << 0 << " ";
			}
			else cout << n-1 << " ";
		}
		cout << "\n";
	}	
	return 0;
}