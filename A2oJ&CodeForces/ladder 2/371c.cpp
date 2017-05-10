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
	string recipe;
	cin >> recipe;
	ll count =0;
	int f1[3];  // B S C 
	REP(i,recipe.length()){
		if(recipe[i] == 'B')f1[0]++;
		else if(recipe[i] == 'S')f1[1]++;
		else if(recipe[i] == 'C')f1[2]++;
	}
	int n[3],p[3];
	REP(i,3)cin >> n[i];
	REP(i,3)cin >> p[i];
	ll R;
	cin >> R;

	int nu[3];
	REP(i,3){
		nu[i] = n[i]/f1[i];
	}

	count += min(min(nu[0],nu[1]),nu[2]);
	int nRem1[3],nRem2[3]; 
	REP(i,3){
		nRem1[i] = ((nu[i]-count)*f1[i] + n[i]%f1[i])/f1[i];
		nRem2[i] = ((nu[i]-count)*f1[i] + n[i]%f1[i])%f1[i];
	}
	//int mq = mq(nRem1[0],nRem1[1]);
	int mq = max(max(nRem1[0],nRem1[1]),nRem1[2]);

	if(nRem1[0] == mq){
		count+= mq;
		if(nRem2[0]>0)count++;
	}
	else if(nRem1[1] == mq){
		count+= mq;
		if(nRem2[1]>0)count++;
	}
	else {
		count+= mq;
		if(nRem2[2]>0)count++;
	}

	ll moneyLeft =0;
	R-((f1[0]-((mq - nRem1[0])*f1[0])+nRem2[0])*p[0]  + (f1[1]-(mq - nRem1[1]*f1[1])+nRem2[1])*p[1]+ (f1[2]-(mq - nRem1[2]*f1[1])+nRem2[2])*p[2]);

	int remHome[3];
	remHome[0]=n[0]%f1[0];
	remHome[1]=n[1]%f1[1];
	remHome[1]=n[1]%f1[1];

	int priceFor1 = p[0]*f1[0] + p[1]*f1[1] + p[2]*f1[2];
	ll fromMarket = 0;
	if(R >= 0){
		fromMarket = R/priceFor1;
		moneyLeft = R % priceFor1;
	}
	count += fromMarket;

	cout << count;
	return 0;
}