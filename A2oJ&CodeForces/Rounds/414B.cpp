#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(ll i=a;i<b;i += c)
#define FORd(i,a,b,c) for(ll i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;

int main(){
	double n,h;
	cin >> n >> h;

	 double iniAr = h/2;
	 double each = iniAr/( double)n;
	 vector < double> height;
     double x = n-1;
	 double base = 1;
	 double h0 = h; 

	while(x--){
		 double h1 ;
		 double b = (2*iniAr)- (h0*base);
		 double c = (2*each*h0) - (2*iniAr*h0) ; 
		h1 = ( (2*b) + sqrt( (b*b) - (4*base*c) ))/(2*base);
		height.push_back(h1);
		h0 = h1;		
		base = 2*(iniAr - each)/h1;
		iniAr = (iniAr - each);
	}

	FORd(i,height.size()-1,0,1){
		printf("%.12f\n", height[i]);
	}


}