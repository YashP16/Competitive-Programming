#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,i;
	cin >> n;
	int a[n],b[n];
	int ea=0,eb=0,oa=0,ob=0;
	FOR(i,0,n,1){
		cin >> a[i] >> b[i];
		if(a[i]%2==0)ea++;
		else oa++;
		if(b[i]%2==0)eb++;
		else ob++;
	}
	if(oa%2==0 && ob%2 ==0)cout << 0;
	else if(oa%2!=0 && ob%2 !=0){
		FOR(i,0,n,1){
			if((a[i]%2!=0 && b[i]%2==0)||(b[i]%2!=0 && a[i]%2==0) && n!=1) {
				cout << 1;
				return 0;
			}
		}
		cout << -1;
	}
	else cout << -1;
	return 0;
}