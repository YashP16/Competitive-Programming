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
	ll n,m,i;
	cin >> n;
	ll a[n]={0};
	ll b[n]={0};
	FOR(i,1,n+1,1){
		cin >> a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	FOR(i,1,n+1,1){
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	cin >>m;
	ll t[m],l[m],r[m];
	FOR(i,0,m,1){
		cin >> t[i] >> l[i] >> r[i];
	}
	FOR(i,0,m,1){
		ll u =0; 
		if(t[i]==1){
			u= a[r[i]]-a[l[i]-1];
		}
		else{

			u = b[r[i]]-b[l[i]-1] ;
		}
		cout << u << endl;
	}
	return 0;
}