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

	int l = a*c/__gcd(a,c);
	int flag = 1;
	int m = d % c;
	int i =0;
	while((b+ i*a) <= l){
		if((b+i*a)%c == m){
			cout << b+i*a << endl;
			return 0;
		}
		i++;
	}
	cout << "-1";
	return 0;
}