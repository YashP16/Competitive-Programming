#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;
int x[13]={2,3,5,7,11,13,17,19,23,29,31,37};

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int i =0;
		ll r =1;
		while(x[i]<=n && i < 13){
			int j=1;
			while(pow(x[i],j)<=n){
				j++;
			}
			r = r*(pow(x[i],j-1));
			i++;
		}
		cout << r << endl;
	}
	return 0;
}