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
	ll n;
	cin >> n;
	vI arr(n);
	REP(i,n)cin >> arr[i];
	vector <pair <ll,ll> > boom(n);
	REP(i,n){
		double x =  sqrt(double(arr[i])); 		
		ll m = (ll)x;	
		boom[i].F = min(abs(SQR((ll)ceil(x))-arr[i]),abs(SQR((ll)floor(x))-arr[i]));
		boom[i].S = arr[i];
	}
	sort(boom.begin(), boom.end());
	int mid = n/2;
	ll count = 0;
	
	// REP(i,n)cout << boom[i].F <<" " << boom[i].S << "\n";

	REP(i,mid){
		count+=boom[i].F;
	}
	FOR(i,mid,n,1){
		if(boom[i].F == 0){
			if(boom[i].S==0)count+= 2;
			else count+= 1;
		}
	}
	cout << count << "\n";
}