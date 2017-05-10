#include <iostream>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b,c) for( i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int t;
	cin >> t;
	ll s[2];
	ll e[2];
	cin >> s[0] >> s[1] >> e[0] >> e[1];
	int i,time=0;
	char d[t];
	ll xdiff = s[0]-e[0];
	ll ydiff = s[1]-e[1]; 
	FOR(i,0,t,1){
		cin >> d[i];
		if(d[i]=='S'&&ydiff > 0)ydiff--;
		else if(d[i]=='N' && ydiff<0)ydiff++;
		else if(d[i]=='E'&&xdiff<0)xdiff++;
		else if(d[i]=='W'&&xdiff > 0)xdiff--;
		time++;
		if(xdiff ==0 && ydiff ==0) break;
	}
	if(xdiff != 0 || ydiff != 0)cout << "-1";
	else cout << time;
	return 0;
}