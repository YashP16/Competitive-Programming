#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility> // for pair
#define REP(i,n) for(i=0;i<n;i++)
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;


int main(){
	bool c[1001]={0};
	int x[1001]={0};
	int y[1001]={0};
	int n,i;
	cin >> n;
	int a[n],b[n];
	int count =0;
	REP(i,n){
		cin >> a[i] >> b[i];
		x[a[i]]++;	
		y[b[i]]++;
	}
	REP(i,n){
		if(a[i]!=b[i] && y[a[i]]>0)count++;
		else if(a[i]==b[i]&& y[a[i]]>1)count++;
	}
	cout << n-count;
	return 0;
}