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

bool sortdes(const pair<ll,pair<int,int> > &a,const pair<ll,pair<int,int> > &b){
    if(a.S.S >b.S.S)return true;
    else if(a.S.S == b.S.S && a.S.F > b.S.F)return true;
    else return false;
}

int dp(vector < pair<ll, pair<int,int> > > a,int n){
	vii
}


int main(){
	int n,k;
	cin >> n >> k;
	vector < pair<ll, pair<int,int> > > a(n);
	
	REP(i,n){
		cin >> a[i].F;
		int x = a[i].F;
		int fives = 0;
		int twos = 0;
		while(x%5==0){
			fives++;
			x = x/5;
		}
		while(x%2==0){
			twos++;
			x = x/2;
		}
		a[i].S.F = twos;
		a[i].S.S = fives;		
	}

	sort (a.begin(), a.end(),sortdes);

	return 0;
}