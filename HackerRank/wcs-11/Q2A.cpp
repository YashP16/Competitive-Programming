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

int modulo(int a,int b,int n){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%n;
        }
        y = (y*y)%n; // squaring the base
        b /= 2;
    }
    return x%n;
}


int main(){
	string s;
	int k,b,m;
	cin >> s >> k >> b >> m;
	int sum = 0;
	int num =0;
	int p = modulo(b,k-1,m);
	FOR(i,0,s.length()+1-k,1){
		if(i==0){
			FOR(j,i,k,1){
				num += ((int)(s[j]-'0')%m) * modulo(b,k-1-j,m) ;
			}
			sum = num %m;
			num = sum;
		}
		else{
			num = ((num - (((int)(s[i-1]-'0')%m)*p))*(b%m)) + ((int)(s[i+k-1]-'0' )%m);
			num = num%m;
			if(num<0) num = m + num;
			sum+= num;
		}
	}
	cout << sum << endl;	
	return 0;
}