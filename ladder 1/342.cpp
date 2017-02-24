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
	int m[n];
	int i;
	int c[7] ={0};
	FOR(i,0,n,1){
		cin >> m[i];
		if(m[i] == 5 || m[i] == 7){
			cout << "-1";
			return 0;
		}
		else{
			c[m[i]]++;
		}
	}
	if(c[1] != n/3 || c[4]>c[2] || c[2]-c[4]+c[3]<c[6] || (c[4] ==0 && c[6] ==0) ){
		cout << -1;
	}
	else{
		FOR(i,0,c[4],1){
			cout << "1 2 4\n";
		}
		FOR(i,0,c[3],1){
			cout << "1 3 6\n";
		}
		FOR(i,0,c[6]-c[3],1){
			cout << "1 2 6\n";
		}
	}
	return 0;
}