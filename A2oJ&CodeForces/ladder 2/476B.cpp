#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <stdio.h>
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
int fact(int n){
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
};

int NCR(int n,int r){
    if(n==r) return 1;
    if (r==0&&n!=0) return 1;
	else return fact(n)/(fact(r)*fact(n-r));;
};

int main(){
	string s1,s2;
	int p1=0,p2=0,q=0;
	cin >> s1 >> s2;
	int i;
	double result;
	REP(i,s1.length()){
		if(s1[i]=='+')p1++;
		if(s2[i]=='+')p2++;
		else if(s2[i]=='?')q++;
	}
	if(q==0){
		if(p1 == p2)result =1;
		else result = 0;	
	}
	else{
		if(p1 < p2) result = 0;
		else if(p1 == p2) result = (double) 1/pow(2,q);
		else result = (double)NCR(q,(p1-p2))/pow(2,q);
	} 

	printf("%1.12f\n", result);


	return 0;
}