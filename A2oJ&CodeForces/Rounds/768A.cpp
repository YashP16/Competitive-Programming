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
	int n,i;
	cin >> n;
	ll a[n];
	FOR(i,0,n,1){
		cin >> a[n];
	}
	sort(a,a+n);
	int count =0;
	FOR(i,1,n-1,1){
		if(a[i]>a[0] && a[i]<a[n-1]){
			count++;
		}
	}
	cout << count;	
	
	return 0;
}