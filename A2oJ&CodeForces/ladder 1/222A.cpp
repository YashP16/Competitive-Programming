#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;
int main(){
	ll n,k;
	cin >> n >> k;
	ll i;
	ll a[n];
	FOR(i,0,n,1){
		cin >> a[i]; 
	}
	ll count =0;
	FOR(i,0,n,1){
		if(a[i]!= a[n-1]){
			if(i >= k-1){
				cout << -1;
				return 0;
			}
			else{
				count = i+1;
			}
		}
	}
	cout << count;
	return 0;
}