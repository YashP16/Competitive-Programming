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
bool isR(int a,int b,int c){
	if((c*c == (a*a)+(b*b))&& c>=a && c>=b)return true;
	else return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int i,j;
		int a,b,c;
		int max = -1;
		if(n%2==0){
			FOR(a,1,n/3,1){
				b = (n*n-(2*a*n))/(2*(n-a));
				c = n-b-a;
				if(isR(a,b,c)){
					int temp = a*b*c;
					if(temp>max)max = temp;
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}