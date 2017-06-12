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
bool a[100][100],b[100][100];
bool check(int m,int n){
	REP(i,m){
		REP(j,n){
			if(b[i][j]==0){
				REP(x,m)if(a[x][j]!=0)return false;
				REP(x,n)if(a[i][x]!=0)return false;
			}
			else{
				bool flag = 0;
				REP(x,m)if(a[x][j]==1){
					flag =1;
					break;
				}
				REP(x,n)if(a[i][x]==1){
					flag =1;
					break;
				}
				if(flag == 0)return false;
			}
		}
	}
	return true;
}

int main(){
	int m,n;
	cin >> m >> n;
	
	REP(i,m)REP(j,n)a[i][j]=1;
	
	REP(i,m)REP(j,n){
		cin >> b[i][j];
		if(b[i][j]==0){
			REP(x,m)a[x][j]=0;
			REP(x,n)a[i][x]=0;
		}
	}

	if(check(m,n)){
		cout << "YES\n" ;
		REP(i,m){
			REP(j,n){
				cout << a[i][j] << " ";	
			}
			cout << endl;
		}
	}
	else cout << "NO\n";
	return 0;
}