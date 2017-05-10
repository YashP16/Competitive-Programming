#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	ll a,b;
	int n,i;
	cin >> a >> b >> n;
	int x,y;
	x = (a*10)%b;
	y = abs((a*10)%b - b);
	if(min(x,y)>9)cout << -1;
	else{
		int c=0;
		if(((a*10)+x)%b == 0)c=(a*10)+x;
		else c=(a*10)+y; 
		cout << c;
		FOR(i,1,n,1){
			cout << 0;
		} 
	}


	
	return 0;
}