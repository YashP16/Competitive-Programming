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
	int n,m;
	cin >> n >> m;
	string f[n];
	int ones[n]={0};
	REP(i,n)cin >> f[i];
	FORd(i,n-1,0,1){
		REP(j,m+2){
			ones[i] += (int)(f[i][j] - '0');
		}
	}
	bool dirn = 0;
	int total = 0;
	FORd(i,n-1,0,1){
		if(dirn == 0){
			int pos = 1;
			while(ones[i]>0 ){
				if(f[i][pos] == '1')ones[i]--;
				pos++;
				total++;	
			}
			pos--;
			if(i!= 0){
				if(pos <= (m+2)/2){
					total += pos + 1;
				}
				else{
					total += m+1 - pos +1;
					dirn = 1;
				}
			}
		}
		else{
			int pos = m;
			while(ones[i]>0 ){
				if(f[i][pos] == '1')ones[i]--;
				pos--;
				total++;	
			}
			pos++;
			if(i!=0){
				if(pos >= (m+2)/2){
					total += m+1 - pos + 1;
				}
				else{
					cout << "yo\n";
					total += pos +1 ;
					dirn = 0;
				}
			}	
		}
	}
	cout << total << "\n";
	return 0;
}