#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,i;
	cin >> n;
	bool c[3002]={0};
	int a[n];
	FOR(i,0,n,1){
		cin >> a[i];
		c[a[i]]=1;
	}
	FOR(i,1,3002,1){
		if(c[i]==0){
			cout << i;
			break;
		}
	}

	
	return 0;
}