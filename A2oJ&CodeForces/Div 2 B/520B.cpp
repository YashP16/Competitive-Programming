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
	int n,m;
	cin >> n >> m;
	int count=0;
	if(n < m){
		queue <int> q;
		q.push(n);
		vi check(pow(10,6)+1,-1);
		check[n]=0;
		while(!q.empty()){
			int f = q.front();
			if(f < m){
				int r = f*2;
				int b = f-1;
				if(check[r] == -1){	
					q.push(r);
					check[r]=check[f]+1;
				}
				if(b>0 && check[b]==-1){
					q.push(b);
					check[b]=check[f]+1;
				}
				q.pop();
			}
			else if(f==m){
				count = check[f];
				break;
			}
			else{
				int b = f-1;
				if(b>0 && check[b]==-1){
					q.push(b);
					check[b]=check[f]+1;
				}
				q.pop();
			}
		}	
	}
	else{
		count += n-m;
	}

	cout << count << "\n";
	return 0;
}