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

int main(){
	int a[26][26]={0};
	int i,j;
	FOR(i,3,23,1){
		FOR(j,3,23,1){
			cin >> a[i][j];
		}
	}
	int max =0;
	FOR(i,3,23,1){
		FOR(j,3,23,1){
			ll top = a[i][j]*a[i-1][j]*a[i-2][j]*a[i-3][j];
			if(top > max)max=top;
			ll bottom = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
			if(bottom > max)max=bottom;
			ll left = a[i][j]*a[i][j-1]*a[i][j-2]*a[i][j-3];
			if(left > max)max=left;
			ll right =  a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
			if(right > max)max=right;
			ll tleft = a[i][j]*a[i-1][j-1]*a[i-2][j-2]*a[i-3][j-3];
			if(tleft > max)max=tleft;
			ll tright = a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
			if(tright > max)max=tright;
			ll bleft = 	a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
			if(bleft > max)max=bleft;
			ll bright = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
			if(bright > max)max=bright;
		}
	}
	cout << max << endl;
	return 0;
}