#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,i;
	cin >> n;
	int a[n];
	int total=0;
	FOR(i,0,n,1){
		cin >> a[i];
		total += a[i];
	}
	if(total%n == 0)cout << n;
	else cout << n-1;
	return 0;
}