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
#define MEM(a,val) memset(a,val,sizef(a))
using namespace std;

int main(){
	fast_io;
	cin.tie(NULL);
	int r,c;
	int ans=0;
	cin >> r >> c;
	string m[r];
	REP(i,r)cin >> m[i];

	vector <int> A;
	
	FOR(i,1,r-1,1){
		FOR(j,1,c-1,1){
			int a = 0;
			while(m[i+a][j]=='G' && m[i-a][j]=='G' && m[i][j+a]=='G' && m[i][j-a]=='G'){
				m[i+a][j] = m[i-a][j]= m[i][j+a] = m[i][j-a] = 'g';
				FOR(k,1,r-1,1){
					FOR(l,1,c-1,1){
						int A = 0;
						while(m[k+A][l]=='G' && m[k-A][l]=='G' && m[k][l+A]=='G' && m[k][l-A]=='G'){
							ans = max(ans,(1+4*a)*(1+4*A));
							A++;
						}

					}
				}
			a++;				
			}
			a = 0;
			while(m[i+a][j]=='g' && m[i-a][j]=='g' && m[i][j+a]=='g' && m[i][j-a]=='g'){
				m[i+a][j] = m[i-a][j]= m[i][j+a] = m[i][j-a] = 'G';
				a++;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}