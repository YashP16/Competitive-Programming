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
	int count =0;
	ll sum = 0;
	int f = 0;
	count++;
	REP(i,n){
		cin >> a[i];
		if(f == 0){
			sum+=count*a[i];
			if(count != k)count++;
		}
		if(f == 1){
			sum+=count*a[i];
			count--; 
		}
		if(i == n-k-1)f = 1;
	}
	printf("%.10f\n",sum/(double)(n-k+1));
}