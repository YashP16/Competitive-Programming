#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	if((double)a/(double)b < (double)c/(double)d){
		ll x = (b*c) - (a*d);
		ll y = b*c;
		ll z = __gcd(x,y);
		cout << x/z << "/" << y/z; 
	}

	else if((double)a/(double)b > (double)c/(double)d){
		ll x = (a*d) - (b*c);
		ll y = a*d;
		ll z = __gcd(x,y);
		cout << x/z << "/" << y/z; 
	} 

	else cout << "0/1";
	return 0;
}