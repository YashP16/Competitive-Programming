#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,i;
	cin >> n;
	int a[n]={0};
	FOR(i,0,n,1){
		cin >> a[i]; 
	}
	int *max = max_element(a,a+n);
	int x = *max;
	int m[x+1]={0};
	//cout << x << endl;
	FOR(i,0,n,1){
		m[a[i]]++; 
	}
	int *f = max_element(m,m+x+1);
	int y = *f;
	
	if(y > (n + 1)/2) cout << "NO";
	else cout << "YES";

	return 0;
}