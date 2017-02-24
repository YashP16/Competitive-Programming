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
vector <int> p(1000001,-1);
bool isPrime(ll n){
	if(p[n]==-1){
		for(ll i =2;i<=(int)sqrt(n);i++){
			if(n%i ==0){
				p[n]=0;
				return false;
			}
		}
		p[n]=1;
		return true;
	}
	else{
		if(p[n]==0) return false;
		else return true;
	}
}
int main(){
	int n,i;
	cin >> n;
	ll a[n];
	FOR(i,0,n,1){
		cin >> a[i];
	}
	FOR(i,0,n,1){
		ll x = (int)sqrt(a[i]);
		if(a[i] == 2 || a[i] == 3 || a[i]==1 ) cout << "NO\n";
		else if(x*x == a[i] && isPrime(x))cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}