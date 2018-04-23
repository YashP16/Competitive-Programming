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
	vi a(n);
	int count = 0;
	REP(i,n)cin >> a[i];	
	
	if(a[0]%2 == 0 || a[n-1]%2== 0)cout << "No\n";
	
	else{
		if(n%2 != 0) cout << "Yes\n";
		else{
			bool flag = 0;
			int len = 0;
			FOR(i,0,n,1){
				if(!flag && a[i]%2 != 0){
					if(i == n-1)count++;
					flag = 1;
					len = 1;
				}
				if(i!=n-1 && flag && a[i]%2!=0 && a[i+1]%2!=0 && (len)%2 != 0){
					count++;
					flag = 0;
					len = 0;
				}

				else len++; 
			}
			if(count%2== 0)cout << "No\n";
			else cout << "Yes\n";

		}
	}



	return 0;
}