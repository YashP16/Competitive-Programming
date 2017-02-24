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
	int n,m,a,b;
	cin >> n >> m;
	int count=0;
	FOR(a,0,(int)sqrt(n)+1,1){
		b = n-(a*a);
		if(a+(b*b)==m)count++;
	}
	cout << count;
	return 0;
}