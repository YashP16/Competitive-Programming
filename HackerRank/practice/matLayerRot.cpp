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
	int m,n,k;
	cin >> m >> n >> k;
	vii mat(m,vi (n));
	REP(i,m)REP(j,n)cin >> mat[i][j];
	
	int numlayer = min(m,n)/2;
	vii layers(numlayer);

	// Parsing layer
	FOR(i,0,numlayer,1){
		int r=i,c=i;
		while(r<m-i-1){
			layers[i].PB(mat[r][c]);
			r++;
		}

		while(c<n-i-1){
			layers[i].PB(mat[r][c]);
			c++;	
		}
		
		while(r>i){
			layers[i].PB(mat[r][c]);
			r--;
		}
		while(c>i){
			layers[i].PB(mat[r][c]);
			c--;
		}
	}
	
	// rotating the matrix
	FOR(i,0,numlayer,1){
		int start =0;
		int len = layers[i].size();
		start = len + ((start - k)%len);
		int count = 0;
		int r=i,c=i;
		while(r<m-i-1){
			mat[r][c]= layers[i][(start+count)%len];
			count++;
			r++;
		}

		while(c<n-i-1){
			mat[r][c]= layers[i][(start+count)%len];
			count++;
			c++;	
		}
		
		while(r>i){
			mat[r][c]= layers[i][(start+count)%len];
			count++;
			r--;
		}
		while(c>i){
			mat[r][c]= layers[i][(start+count)%len];
			count++;
			c--;
		}
	}

	REP(i,m){
		REP(j,n) cout << mat[i][j] << " ";
		cout << "\n";
	}

	return 0;
}