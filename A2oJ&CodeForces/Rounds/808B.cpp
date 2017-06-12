#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;
	
int main(){
	int n,k;
	cin >>  n >> k;
	ll a[n];
	REP(i,n)cin >> a[i];
	ll sum=0;
	ll temp =0;
	FOR(i,0,n-k+1,1){
		if(i ==0){
			FOR(j,0,k,1){
				temp+= a[j];
			}
		}
		else{
			temp= temp - a[i-1]+a[i+k-1];
		}
		sum += (double) temp;
	}

	printf("%.10f\n",(double)sum/(double)(n-k+1));

}