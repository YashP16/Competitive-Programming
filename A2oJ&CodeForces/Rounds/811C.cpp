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

int counter(int **mat,bool ** check,int l,int r){
	int count = 0;
	FOR(i,1,n+1,1){
		FOR(j,l,r+1,1){
			if(check[i][j]!= 1){
				stack < pair <int,int> > s;
				s.push(make_pair(i,j));
				int a = mat[s.top().F][s.top().S];
				while(!s.empty()){
					if(check[s.top().F][s.top().S+1] != 1 && mat[s.top().F][s.top().S+1] ==  a){
						check[s.top().F][s.top().S+1] = 1;
						s.push(make_pair)
					}  
				}
			}
		}
	}
}


int main(){
	int n,m,q;
	cin >> n >> m >> q;
	int mat[n+2][m+2];
	bool check[n+2][m+2] = {0};
	FOR(i,0,n+2,1){
		FOR(j,0,m+1,1){
			if(i == 0 || j == 0 || i == n+1 || j == m+1)check[i][j]=1;
			else cin >> mat[i][j];
		}
	}
	int l,r;
	while(q--){
		cin >> l >> r;
	}
}