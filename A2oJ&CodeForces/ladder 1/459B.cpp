#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	ll n;
	cin >> n;
	ll b[n];
	ll i,j;
	FOR(i,0,n,1){
		cin >> b[i];
	}
	sort(b,b+n);
	ll maxd = b[n-1]-b[0];
	ll count =0;
	if(maxd !=0){
		FOR(i,0,n-1,1){
			if(b[i] != b[0])
			break;
		}
		FORd(j,n-1,0,1){
			if(b[n-1]!= b[j])
			break;
		}
		count = (i)*(n-j-1);
	} 
	else{
		count = n*(n-1)/2;
	}
	cout << maxd << " " << count;
}