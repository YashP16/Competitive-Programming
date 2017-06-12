
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
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
	int a[3];
	pair <int,int> f[3];
	int count = 0;
	cin >> a[0] >> a[1] >> a[2];
	int min =2;
	REP(i,3){
		count += a[i]/3;
		f[i].first= a[i]/3;
		f[i].second = a[i]%3;
		if(min > a[i]%3) min = a[i]%3;
	}
	sort(f,f+3);
	if(min != 0){
		count+= min;
		REP(i,3)f[i].second-=min;
	}
	int sum =0;
	REP(i,3){
		sum+= f[i].second;
	}
	if(sum>= 4 && f[0].first>=1)count ++;
	

	cout << count;

	return 0;
}