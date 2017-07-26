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
	int t,m,n;
	string a,b;
	cin >> t;
	while(t--){
		cin >> m >> n;
		cin >> a >> b;
		
		if(a.length()<b.length()){
			swap(a,b);
			swap(m,n);
		}
		int x,mi,count = 0;
		int max =0;
		REP(i,m){
			x = i;
			mi = 1;
			count = 0;
			int j = 0,y=0;
			bool flag;
			while(j<n){
				y = j;
				while(a[i]==b[y]){
					count++;
					i++;
					y++;
					if(i == m || y == n)break;
				}
				if(count>max){
					max = count;
					mi = count;
				}
				i = x;
				j++;
				count = 0;
			}
			i = x;
			if(mi>1)i+= mi-1;
		}
		cout << max << "\n";
	}
	return 0;
}