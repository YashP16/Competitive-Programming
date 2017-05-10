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
	int a[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int n,m,i;
	cin>>n>>m;
	FOR(i,0,15,1){
		if(a[i]==n){
			if(a[i+1]==m)cout << "YES";
			else cout << "NO";
			break;
		}
	}

	
	return 0;
}