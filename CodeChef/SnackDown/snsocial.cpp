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
	int t,n,m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int mat[n][m];
		int m1 = 0;
		REP(i,n){
			REP(j,m){
				cin >> mat[i][j];
				if(m1 < mat[i][j])m1 = mat[i][j];
			}
		}
		vector <pair <int,int> > pos;
		REP(i,n){
			REP(j,m){
				if(mat[i][j] == m1){
					pos.PB(make_pair(i,j));
				}
			}
		}
		int m2 = 0;
		REP(i,n){
			REP(j,m){
				if(mat[i][j]!= m1){
					int min = MAX,temp =0;
					REP(x,pos.size()){
						temp = max(abs(pos[x].F - i),abs(pos[x].S - j)); 
						if(temp < min )min = temp;
						if(min == 1)break;
					}
					if(min > m2)m2 = min;
				}
			}
		}
		cout << m2 << "\n";

	}
	
	return 0;
}