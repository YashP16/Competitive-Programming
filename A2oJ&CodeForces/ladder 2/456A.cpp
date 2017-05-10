#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;

int main(){
	int n,i;
	cin >> n;
	pair <int,int> p[n];
	int flag =1;
	FOR(i,0,n,1){
		cin >> p[i].first >> p[i].second;
		if(p[i].first!=p[i].second){
			flag =0;
		}
	}
	if(flag == 1)cout <<"Poor Alex";
	else cout << "Happy Alex";


	return 0;
}