#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	ll n;
	ll i;
	cin >> n;
	ll a[n];
	ll b[n];
	ll count =0;
	FOR(i,0,n,1){
		cin >> a[i];
		b[i]=i+1;	
	}
	sort(a,a+n);
	FOR(i,0,n,1){
		count+= abs(b[i] - a[i]);
		a[i]=i+1;
	}
	cout << count << endl;
	return 0;
}