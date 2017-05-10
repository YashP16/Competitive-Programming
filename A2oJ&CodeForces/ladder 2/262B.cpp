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
	int n,k,i;
	cin >> n >> k;
	int a[n];
	int sum =0;
	REP(i,n){
		cin >> a[i];
		if(a[i]<0 && k>0){
			a[i]=(-1)*a[i];
			k--;
		}
	}
	if(k>0){
		sort(a,a+n);
		a[0] = (pow(-1,k))*a[0];
	}
	FOR(i,0,n,1){
		sum+= a[i];
	}
	cout << sum;
	return 0;
}