#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
using namespace std;

int main(){
	int n,i;
	cin >> n;
	ll a[n];
	FOR(i,0,n,1){
		cin >> a[i];
	}
	int temp =2;
	int count =2;
	int pointer=0;
	i = pointer+2;
	if(n == 1) {
		cout << 1 ;
		return 0;
	}
	while(i!=n){
		if(a[i-1]+a[i-2]== a[i]){
			temp++;
			i++;
		}
		else{
			pointer = i-1;
			i = pointer+2;
			if(temp>count)count =temp;
			temp =2;
		}
		if(i == n){
			if(temp > count) count =temp;
			break;
		}
	}
	cout << count;
	
	return 0;
}