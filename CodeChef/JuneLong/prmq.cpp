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


bool isPrime(ll n){
    if(n == 2)return true;
    ll i;
    FOR(i,2,sqrt(n)+1,1){
        if(n%i ==0){
            return false;
        }
    }
    return true;
}


int f(int *a,int L,int R,int  X,int  Y) {
     int result = 0;
     FOR( i, X,Y+1,1) {
         if(isPrime(i)) {
             FOR( j,L-1,R,1){
                  int number = a[j];
                  int exponent = 0;
                  while( number % i == 0 ) {
                     exponent = exponent + 1 ;
                     number = number/i;
                  }
                  result = result + exponent;
              }
         }
     }
     return result;
}

int main(){
	fast_io;
	cin.tie(NULL);
	int n,q,l,r,x,y;
	cin >> n;
	int a[n];
	REP(i,n)cin >> a[i];
	cin >> q;
	while(q--){
		cin >> l >> r >> x >> y;
		cout << f(a,l,r,x,y) << "\n";
	}
	return 0;
}