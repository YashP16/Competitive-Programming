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
	ll x,y,n;
	cin >> x >> y >> n;
	ll m[6]={x,y,y-x,-x,-y,x-y};
	int index=(n-1)%6;
	ll a = m[index];
	ll mod = ((1000000007*2)+a) % 1000000007;
	cout << mod;
	return 0;
}