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
	int p,q,l,r;
	cin >> p >> q >> l >> r;
	pair <int,int> a[p],c[q];
	REP(i,p)cin >> a[i].F >> a[i].S;
	REP(i,q)cin >> c[i].F >> c[i].S;
	
	bool d[a[p-1].S+1];

	REP(i,p){
		FOR(j,a[i].F,a[i].S+1,1){
			d[j]=1;
		}
	}
	int count = 0;
	FOR(i,l,r+1,1){
		FOR(j,0,q,1){
			FOR(k,c[j].F+i,max(c[j].S+i,a[p-1].S+1),1){
				if()
			}
		}
	}
	cout << count << endl;

}