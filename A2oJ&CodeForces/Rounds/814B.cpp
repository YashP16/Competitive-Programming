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
	fast_io;
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n],b[n];
	REP(i,n)cin >> a[i];
	REP(i,n)cin >> b[i];

	int dcount=0;
	int index = 0;
	REP(i,n){
		if(a[i]!=b[i]){
			dcount++;
		}
	}

	if(dcount==2){
		int flag =0;
		vector < int > v1(n),v2(n);
			
		int v1s=0;
		int v2s=0;

		REP(i,n){
			if(a[i]!= b[i]){
				if(flag == 0){
					v1[i]=a[i];
					v2[i]=b[i];
					flag = 1;
				}
				else{
					v1[i]=b[i];
					v2[i]=a[i];
				}
			}
			else{
				v1[i]=a[i];
				v2[i]=b[i];	
			}
			v1s += v1[i];
			v2s += v2[i];
		}

		if(v1s == ((n*(n+1))/2)){
			REP(i,n)cout << v1[i] << " ";
		}
		else REP(i,n) cout << v2[i] << " ";
	}
	else{
		vector <int> v(n);
		int vs = 0;
		REP(i,n){
			if(a[i]!=b[i]){
				v[i] = 0;
				index = i;
			}
			else v[i] = a[i];
			vs+= v[i];
		}
		REP(i,n){
			if(i==index) cout << ((n*(n+1))/2) - vs << " ";   
			else cout << v[i] << " ";
		}
	}
	cout << endl;
	return 0;
}