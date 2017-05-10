#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	ll y,k, n;
	cin >> y >> k>> n;
	int flag =0;
	int d = n/k + 1;
	int c;
	int x=0;
	while(d--){
		if(k*c - y > 0){
			flag = 1;
			cout << k*c-y << " ";
			x++;
		}
		c++;
	}
	if(flag == 0)cout << -1;
	return 0;
}