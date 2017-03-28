// Maximum subarray sum 
// Kadane's algorithms

#include <iostream>
#include <algorithm>
#include <string.h>
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


//-2 -3 4 -1 -2 5 1 -3

int maxSubArraySum(int l[],int n){
	int max_so_far  = l[0];
	int max_current = l[0];
	FOR(i,1,n,1){
		max_current = max(l[i],max_current + l[i]);
		max_so_far = max(max_so_far,max_current);
	}
	return max_so_far;
}

int main(){
	int n; 
	cin >> n;
	int list[n];
	REP(i,n){
		cin >> list[i];
	}
	cout << maxSubArraySum(list,n) << endl;
	return 0;
}