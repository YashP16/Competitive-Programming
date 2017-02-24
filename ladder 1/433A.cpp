#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n;
	cin >> n;
	int i;
	int a[n];
	int c[2]={0};
	FOR(i,0,n,1){
		cin >> a[i];
		if(a[i]==100)c[0]++;
		else c[1]++;
	}	
	if(c[1]%2 == 0){
		if(c[0]%2 ==0) cout << "YES";
		else cout << "NO";
	}
	else{
		if(c[0]%2 == 0 && c[0]!=0)cout << "YES";
		else cout << "NO";
	}

	return 0;
}