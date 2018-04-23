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
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector <vector<char> > mat(n,vector<char>(m));
		string s1='',s2='';
		REP(i,m){
			if(i&1 == 0){
				s1 += 'R';
				s2 += 'G';
			}
			else{
				s1 += 'G';
				s2 += 'R';	
			} 
		}
		int t1rc = 0,t2rc = 0,t1gc=0,t2gc = 0;
		REP(i,n){
			REP(j,m){
				cin >> mat[i][j];
				if(i&1 == 0){
					if(s1[m] != mat[i][j]){
						if(s1[m]=='R') t1gc++;
						else t1rc++;
					}
					else if(s2[m] != mat[i][j]){
						if(s1[m]=='R') t2gc++;
						else t2rc++;
					}
				}
			}
		}
	}	
	return 0;
}