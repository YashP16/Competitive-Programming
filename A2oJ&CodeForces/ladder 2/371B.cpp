#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;


int main(){
	ll a,b;
	cin >> a >> b;
	int a2=0,a3=0,a5=0,b2=0,b3=0,b5=0;
	while(a%2 == 0 || a%5 == 0 || a%3 == 0){
		if(a%2 == 0){
			a2++;
			a = a/2;
		}
		else if(a%3 == 0){
			a3++;
			a = a/3;
		}
		else{
			a5++;
			a= a/5;
		}
	}
	while(b%2 == 0 || b%5 == 0 || b%3 == 0){
		if(b%2 == 0){
			b2++;
			b = b/2;
		}
		else if(b%3 == 0){
			b3++;
			b = b/3;
		}
		else{
			b5++;
			b= b/5;
		}
	}
	if(a!= b)cout << -1;
	else cout << abs(a5-b5)+abs(a2-b2)+abs(a3-b3);
	return 0;
}
