#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
using namespace std;

int main(){
	int n,i;
	cin >> n;
	int a[n];
	FOR(i,0,n,1){
		cin >> a[i];
	}
	sort(a,a+n);
	swap(a[0],a[n-1]);
	FOR(i,0,n,1){
		cout <<  a[i] << " ";
	}
	return 0;
}