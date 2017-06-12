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
	int a[4][4];
	REP(i,4){
		REP(j,4){
			cin >> a[i][j];
		}
	}
	bool flag =0;
	if(a[0][0]== 1 && (a[0][3]==1 || a[3][3]==1))cout << "YES\n";	
	else if(a[0][1]== 1 && (a[0][3]==1 || a[2][3]==1))cout << "YES\n";	
	else  if(a[0][2]== 1 && (a[0][3]==1 || a[1][3]==1))cout << "YES\n";	
	
	else  if(a[1][0]== 1 && (a[1][3]==1 || a[0][3]==1))cout << "YES\n";	
	else  if(a[1][1]== 1 && (a[1][3]==1 || a[3][3]==1))cout << "YES\n";	
	else  if(a[1][2]== 1 && (a[1][3]==1 || a[2][3]==1))cout << "YES\n";	
	
	else  if(a[2][0]== 1 && (a[2][3]==1 || a[1][3]==1))cout << "YES\n";	
	else  if(a[2][1]== 1 && (a[2][3]==1 || a[0][3]==1))cout << "YES\n";	
	else  if(a[2][2]== 1 && (a[2][3]==1 || a[3][3]==1))cout << "YES\n";	
	
	else  if(a[3][0]== 1 && (a[3][3]==1 || a[2][3]==1))cout << "YES\n";	
	else  if(a[3][1]== 1 && (a[3][3]==1 || a[1][3]==1))cout << "YES\n";	
	else  if(a[3][2]== 1 && (a[3][3]==1 || a[0][3]==1))cout << "YES\n";	
		
	else cout << "NO\n";
	return 0;
}