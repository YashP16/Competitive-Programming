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

bool sortdes(ll &a,ll &b){
	if(a>b)return true;
	else return false;
}
int main(){
	ll i,n,k;
	ll c[26]={0};
	string a;
	cin >> n >> k >> a;
	FOR(i,0,a.length(),1){
		c[(char)a[i]-'A']++;
	}
	ll coins =0;
	int p=0;
	sort(c,c+26,sortdes);
	while(k>0){
		if(k >= c[p]){
			coins += c[p]*c[p];
			k -= c[p];
			p++;
		}
		else{
			coins+= k*k;
			k =0;
		}
	}
	cout << coins;
		
	return 0;
}