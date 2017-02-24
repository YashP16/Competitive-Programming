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
	int n,a[3];
	cin >> n >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	int x=0,y=0,z=0;
	int max=0;
	FOR(x,0,(n/a[0])+1,1){
		FOR(y,0,((n-(x*a[0]))/a[1])+1,1){
			if((n-(x*a[0])-(y*a[1]))%a[2]==0){		
				z=(n-(x*a[0])-(y*a[1]))/a[2];
				if(x+y+z>max)max=x+y+z;
			}
		}
	}
	cout << max;

	return 0;
}