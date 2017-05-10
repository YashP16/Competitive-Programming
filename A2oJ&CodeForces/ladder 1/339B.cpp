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
	int n,m,i;
	cin >> n >> m;
	int a[m];
	FOR(i,0,m,1){
		cin >> a[i];
	}	
	ll count=a[0]-1;

	FOR(i,1,m,1){
		if(a[i]<a[i-1]) count+= n-a[i-1]+a[i];
		else count+= a[i]-a[i-1];
	}
	cout << count;
	return 0;
}