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
void bondMaker(int sum, int max,int maxI,int *result,int *a){	
	if(maxI==0){
		if(a[1]-a[2]!=0){
			result[1]=(a[1]+a[2]-max)/2;
			result[0]=a[1]-result[1];
			result[2]=a[2]-result[1];
		}
		else if(a[1]-a[2]==0 && a[1]+a[2]>max){
			result[0]=max/2;	
			result[1]=a[1]-result[0];
			result[2]=max/2;
		}
		else{
			result[0]=max/2;	
			result[1]=0;
			result[2]=max/2;
		}
	}
	else if(maxI==1){
		if(a[0]-a[2]!=0){
			result[2]=(a[0]+a[2]-max)/2;
			result[0]=a[0]-result[2];
			result[1]=a[2]-result[2];
		}
		else if(a[1]-a[2]==0 && a[1]+a[2]>max){
			result[0]=max/2;	
			result[2]=a[2]-result[0];
			result[1]=max/2;
		}
		else{
			result[0]=max/2;	
			result[1]=max/2;
			result[2]=0;
		}
	}
	else{
		if(a[0]-a[1]!=0){
			result[0]=(a[0]+a[1]-max)/2;
			result[1]=a[1]-result[0];
			result[2]=a[0]-result[0];
		}
		else if(a[0]-a[1]==0 && a[1]+a[0]>max){
			result[0]=a[1]-result[0];
			result[1]=max/2;	
			result[2]=max/2;
		}
		else{
			result[0]=0;	
			result[1]=max/2;
			result[2]=max/2;
		}	
	}	
}
int main(){
	int a[3],i;
	int result[3];
	int max=0,sum =0;
	int maxI;
	REP(i,3){
		cin >> a[i];
		if(a[i]>max){
			max = a[i];
			maxI = i;
		}
		sum+= a[i];
	}
	if(sum%2 == 0 && sum-max >= max){
		bondMaker(sum,max,maxI,result,a);
		cout << result[0] << " " <<result[1] << " " << result[2] << "\n";
		return 0;
	}
	else{
		cout << "Impossible";
	}
	return 0;
}