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

bool check(int a,int b,int c,int d){
	int x1 = min(a,b);
	int x2 = max(a,b);
	int x3 = min(c,d);
	int x4 = max(c,d);
	if((x1 < x3 && x3 < x2 && x2 < x4) || (x3 < x1 && x1 < x4 && x4 < x2))return true;
	return false;
}

int main(){
	int n;
	cin >> n;
	int p[n];
	REP(i,n)cin >> p[i];
	FOR(i,0,n-1,1){
		FOR(j,0,n-1,1){
			if(i!=j){
				if(check(p[i],p[i+1],p[j],p[j+1])){
					cout << "yes";
					return 0;
				}
			}
		}
	}
	cout << "no";
	return 0;
}