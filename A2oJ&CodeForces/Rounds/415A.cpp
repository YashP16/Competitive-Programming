#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stack>
#include <limits>
#include <vector>
#include <stack>
#include <sstream>
#include <queue>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> 9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
#define PB push_back
#define sz size()
#define InF  2147483647
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int a[n];
	int sum =0;
	REP(i,n){
	    cin >> a[i];
		sum+= a[i];
	}
	float a1 = k - 0.5;
	float b = sum - a1*n;
	int count = 0;
	int x = 0;

	while(b + x < a1*count){
		x+= k;
		count ++; 
	}
	cout << count << endl;

	return 0;
}