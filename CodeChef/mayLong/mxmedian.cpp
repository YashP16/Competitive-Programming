// Epic bithaya hai yaar 

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


int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		int a[2*n+1];
		int c[2*n+1];
		
		FOR(i,1,2*n+1,1){
			cin >> a[i];
			c[i] = a[i];
		}
		
		sort(c+1,c+(2*n)+1);
		int med = c[2*n-(n/2)];
		cout << med << endl;

		int count = 1;
		FOR(i,1,2*n+1,2){
			a[i] = c[count];
			count++;
		}
		FOR(i,2,2*n+1,2){
			a[i]=c[count];
			count++;
		}

		FOR(i,1,2*n+1,1)cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
