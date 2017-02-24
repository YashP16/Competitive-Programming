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
struct pa{
	ll first;
	ll second;
	int pos;
};
bool sortf(pa &a,pa &b){
    if(a.first <b.first)return true;
    else if(a.first == b.first && a.second > b.second)return true;
    else return false;
}
int main(){
	int n,i;
	cin >> n;
	pa p[n];
	int max=0;
	FOR(i,0,n,1){
		cin >> p[i].first >> p[i].second;
		p[i].pos = i+1;
		if(p[i].second>max)max =p[i].second; 
	}
	sort(p,p+n,sortf);
	if(p[0].second >=max) cout << p[0].pos;
	else cout << -1;
	
	return 0;
}